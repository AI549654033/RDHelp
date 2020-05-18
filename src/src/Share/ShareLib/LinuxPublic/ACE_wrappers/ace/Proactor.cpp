// Proactor.cpp,v 4.127 2002/11/23 22:55:03 shuston Exp

#include "ace/Proactor.h"

#if ((defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) || (defined (ACE_HAS_AIO_CALLS) || defined(ACE_HAS_AIO_EMULATION)))
// This only works on Win32 platforms and on Unix platforms with aio
// calls.

#include "ace/Proactor_Impl.h"
#include "ace/Object_Manager.h"
#include "ace/Task_T.h"
#include "ace/Log_Msg.h"
#include "ace/Framework_Component.h"

#if !defined (ACE_HAS_WINCE) && !defined (ACE_LACKS_ACE_SVCCONF)
#    include "ace/Service_Config.h"
#  endif /* !ACE_HAS_WINCE && !ACE_LACKS_ACE_SVCCONF */

ACE_RCSID(ace, Proactor, "Proactor.cpp,v 4.129 2003/08/04 03:53:52 dhinton Exp")


#if defined (ACE_HAS_AIO_CALLS) || defined(ACE_HAS_AIO_EMULATION)
#   include "ace/POSIX_Proactor.h"
#   define OS_AIO_RESULT     ACE_POSIX_Asynch_Result
#else /* !ACE_HAS_AIO_CALLS */
#   include "ace/WIN32_Proactor.h"
#   define OS_AIO_RESULT     ACE_WIN32_Asynch_Result
#endif /* ACE_HAS_AIO_CALLS */

#if !defined (__ACE_INLINE__)
#include "ace/Proactor.inl"
#endif /* __ACE_INLINE__ */


#include "ace/Auto_Event.h"


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/// Process-wide ACE_Proactor.
ACE_Proactor *ACE_Proactor::proactor_ = 0;

/// Controls whether the Proactor is deleted when we shut down (we can
/// only delete it safely if we created it!)
int ACE_Proactor::delete_proactor_ = 0;



/**
 * @class ACE_Proactor_Timer_Handler
 *
 * @brief A Handler for timer. It helps in the management of timers
 * registered with the Proactor.
 *
 * This object has a thread that will wait on the earliest time
 * in a list of timers and an event. When a timer expires, the
 * thread will post a completion event on the port and go back
 * to waiting on the timer queue and event. If the event is
 * signaled, the thread will refresh the time it is currently
 * waiting on (in case the earliest time has changed).
 */
class ACE_Proactor_Timer_Handler : public ACE_Task <ACE_NULL_SYNCH>
{

  /// Proactor has special privileges
  /// Access needed to: timer_event_
  friend class ACE_Proactor;

public:
  /// Constructor.
  ACE_Proactor_Timer_Handler (ACE_Proactor &proactor);

  /// Destructor.
  virtual ~ACE_Proactor_Timer_Handler (void);

  /// Proactor calls this to shut down the timer handler
  /// gracefully. Just calling the destructor alone doesnt do what
  /// <destroy> does. <destroy> make sure the thread exits properly.
  int destroy (void);

protected:
  /// Run by a daemon thread to handle deferred processing. In other
  /// words, this method will do the waiting on the earliest timer and
  /// event.
  virtual int svc (void);

  /// Event to wait on.
  ACE_Auto_Event timer_event_;

  /// Proactor.
  ACE_Proactor &proactor_;

  /// Flag used to indicate when we are shutting down.
  int shutting_down_;
};

ACE_Proactor_Timer_Handler::ACE_Proactor_Timer_Handler (ACE_Proactor &proactor)
  : ACE_Task <ACE_NULL_SYNCH> (&proactor.thr_mgr_),
    proactor_ (proactor),
    shutting_down_ (0)
{
}

ACE_Proactor_Timer_Handler::~ACE_Proactor_Timer_Handler (void)
{
  // Mark for closing down.
  this->shutting_down_ = 1;

  // Signal timer event.
  this->timer_event_.signal ();

  // Wait for the Timer Handler thread to exit.
  this->thr_mgr ()->wait_grp (this->grp_id ());
}

int
ACE_Proactor_Timer_Handler::svc (void)
{
  ACE_Time_Value absolute_time;
  ACE_Time_Value relative_time;
  int result = 0;

  while (this->shutting_down_ == 0)
    {
      // Check whether the timer queue has any items in it.
      if (this->proactor_.timer_queue ()->is_empty () == 0)
        {
          // Get the earliest absolute time.
          absolute_time = this->proactor_.timer_queue ()->earliest_time ();

          // Get current time from timer queue since we don't know
          // which <gettimeofday> was used.
          ACE_Time_Value cur_time = this->proactor_.timer_queue ()->gettimeofday ();

          // Compare absolute time with curent time received from the
          // timer queue.
          if (absolute_time > cur_time)
            relative_time = absolute_time - cur_time;
          else
            relative_time = 0;

          // Block for relative time.
          result = this->timer_event_.wait (&relative_time, 0);
        }
      else
        // The timer queue has no entries, so wait indefinitely.
        result = this->timer_event_.wait ();

      // Check for timer expiries.
      if (result == -1)
        {
          switch (errno)
            {
            case ETIME:
              // timeout: expire timers
              this->proactor_.timer_queue ()->expire ();
              break;
            default:
              // Error.
              ACE_ERROR_RETURN ((LM_ERROR,
                                 ACE_LIB_TEXT ("%N:%l:(%P | %t):%p\n"),
                                 ACE_LIB_TEXT ("ACE_Proactor_Timer_Handler::svc:wait failed")),
                                -1);
            }
        }
    }
  return 0;
}

// *********************************************************

ACE_Proactor_Handle_Timeout_Upcall::ACE_Proactor_Handle_Timeout_Upcall (void)
  : proactor_ (0)
{
}

int
ACE_Proactor_Handle_Timeout_Upcall::proactor (ACE_Proactor &proactor)
{
  if (this->proactor_ == 0)
    {
      this->proactor_ = &proactor;
      return 0;
    }
  else
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_LIB_TEXT ("ACE_Proactor_Handle_Timeout_Upcall is only suppose")
                       ACE_LIB_TEXT (" to be used with ONE (and only one) Proactor\n")),
                      -1);
}


int
ACE_Proactor_Handle_Timeout_Upcall::registration (TIMER_QUEUE &,
                                                  ACE_Handler *,
                                                  const void *)
{
  return 0;
}

int
ACE_Proactor_Handle_Timeout_Upcall::preinvoke (TIMER_QUEUE &,
                                               ACE_Handler *,
                                               const void *,
                                               int,
                                               const ACE_Time_Value &,
                                               const void *&)
{
  return 0;
}

int
ACE_Proactor_Handle_Timeout_Upcall::postinvoke (TIMER_QUEUE &,
                                                ACE_Handler *,
                                                const void *,
                                                int,
                                                const ACE_Time_Value &,
                                                const void *)
{
  return 0;
}

int
ACE_Proactor_Handle_Timeout_Upcall::timeout (TIMER_QUEUE &,
                                             ACE_Handler *handler,
                                             const void *act,
                                             int,
                                             const ACE_Time_Value &time)
{
  if (this->proactor_ == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_LIB_TEXT ("(%t) No Proactor set in ACE_Proactor_Handle_Timeout_Upcall,")
                       ACE_LIB_TEXT (" no completion port to post timeout to?!@\n")),
                      -1);

  // Create the Asynch_Timer.
  ACE_Asynch_Timer asynch_timer (handler, time, act, 0 , 0, 0);
 
  // Post a completion.
  if (this->proactor_->post_completion (asynch_timer) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_LIB_TEXT ("Failure in dealing with timers: ")
                       ACE_LIB_TEXT ("post_completion failed\n")),
                      -1);
  return 0;
}

int
ACE_Proactor_Handle_Timeout_Upcall::cancel_type (TIMER_QUEUE &,
                                                 ACE_Handler *,
                                                 int,
                                                 int &)
{
  // Do nothing
  return 0;
}

int
ACE_Proactor_Handle_Timeout_Upcall::cancel_timer (TIMER_QUEUE &,
                                                  ACE_Handler *,
                                                  int,
                                                  int)
{
  // Do nothing
  return 0;
}

int
ACE_Proactor_Handle_Timeout_Upcall::deletion (TIMER_QUEUE &,
                                              ACE_Handler *,
                                              const void *)
{
  // Do nothing
  return 0;
}


// *********************************************************************

ACE_Proactor::ACE_Proactor (ACE_Proactor_Impl *implementation,
                            int delete_implementation,
                            TIMER_QUEUE *tq)
  : implementation_ (0),
    delete_implementation_ (delete_implementation),
    timer_handler_ (0),
    timer_queue_ (0),
    delete_timer_queue_ (0),
    end_event_loop_ (0),
    event_loop_thread_count_ (0)
{
  this->implementation (implementation);

  if (this->implementation () == 0)
    {
#if defined (ACE_HAS_AIO_CALLS) || defined(ACE_HAS_AIO_EMULATION)

      // POSIX Proactor.
       ACE_NEW (implementation, ACE_POSIX_Proactor);

//#  if defined (ACE_POSIX_AIOCB_PROACTOR)
//      ACE_NEW (implementation, ACE_POSIX_AIOCB_Proactor);
//#  elif defined (ACE_POSIX_SIG_PROACTOR)
//      ACE_NEW (implementation, ACE_POSIX_SIG_Proactor);
//#  else /* Default is to use the SIG one */
//#    if defined(ACE_HAS_POSIX_REALTIME_SIGNALS)
//      ACE_NEW (implementation, ACE_POSIX_SIG_Proactor);
//#    else
//      ACE_NEW (implementation, ACE_POSIX_AIOCB_Proactor);
//#    endif /* ACE_HAS_POSIX_REALTIME_SIGNALS */
//#  endif /* ACE_POSIX_AIOCB_PROACTOR */



#elif (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
      // WIN_Proactor.
      ACE_NEW (implementation,
               ACE_WIN32_Proactor);
#endif /* ACE_HAS_AIO_CALLS */
      this->implementation (implementation);
      this->delete_implementation_ = 1;
    }

  // Set the timer queue.
  this->timer_queue (tq);

  // Create the timer handler
  ACE_NEW (this->timer_handler_,
           ACE_Proactor_Timer_Handler (*this));

  // Activate <timer_handler>.
  if (this->timer_handler_->activate (THR_NEW_LWP) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_LIB_TEXT ("%N:%l:(%P | %t):%p\n"),
                ACE_LIB_TEXT ("Task::activate:could not create thread\n")));
}

ACE_Proactor::~ACE_Proactor (void)
{
  this->close ();
}

ACE_Proactor *
ACE_Proactor::instance (size_t /* threads */)
{
  ACE_TRACE ("ACE_Proactor::instance");

  if (ACE_Proactor::proactor_ == 0)
    {
      // Perform Double-Checked Locking Optimization.
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                                *ACE_Static_Object_Lock::instance (),
                                0));

      if (ACE_Proactor::proactor_ == 0)
        {
          ACE_NEW_RETURN (ACE_Proactor::proactor_,
                          ACE_Proactor,
                          0);

          ACE_Proactor::delete_proactor_ = 1;
          ACE_REGISTER_FRAMEWORK_COMPONENT(ACE_Proactor, ACE_Proactor::proactor_);
        }
    }
  return ACE_Proactor::proactor_;
}

ACE_Proactor *
ACE_Proactor::instance (ACE_Proactor * r, int delete_proactor)
{
  ACE_TRACE ("ACE_Proactor::instance");

  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                            *ACE_Static_Object_Lock::instance (), 0));

  ACE_Proactor *t = ACE_Proactor::proactor_;

  ACE_Proactor::delete_proactor_ = delete_proactor;
  ACE_Proactor::proactor_ = r;
  ACE_REGISTER_FRAMEWORK_COMPONENT(ACE_Proactor, ACE_Proactor::proactor_);

  return t;
}

void
ACE_Proactor::close_singleton (void)
{
  ACE_TRACE ("ACE_Proactor::close_singleton");

  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, ace_mon,
                     *ACE_Static_Object_Lock::instance ()));

  if (ACE_Proactor::delete_proactor_)
    {

      delete ACE_Proactor::proactor_;
      ACE_Proactor::proactor_ = 0;
      ACE_Proactor::delete_proactor_ = 0;
    }
}

const ACE_TCHAR *
ACE_Proactor::dll_name (void)
{
  return ACE_LIB_TEXT ("ACE");
}

const ACE_TCHAR *
ACE_Proactor::name (void)
{
  return ACE_LIB_TEXT ("ACE_Proactor");
}

int
ACE_Proactor::check_reconfiguration (ACE_Proactor *)
{
#if !defined (ACE_HAS_WINCE)  &&  !defined (ACE_LACKS_ACE_SVCCONF)
  if (ACE_Service_Config::reconfig_occurred ())
    {
      ACE_Service_Config::reconfigure ();
      return 1;
    }
#endif /* ! ACE_HAS_WINCE || ! ACE_LACKS_ACE_SVCCONF */
  return 0;
}

int
ACE_Proactor::proactor_run_event_loop (PROACTOR_EVENT_HOOK eh)
{
  ACE_TRACE ("ACE_Proactor::proactor_run_event_loop");
  int result = 0;

  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, mutex_, -1));

    // Early check. It is ok to do this without lock, since we care just
    // whether it is zero or non-zero.
    if (this->end_event_loop_ != 0)
      return 0;

    // First time you are in. Increment the thread count.
    this->event_loop_thread_count_ ++;
  }

  // Run the event loop.
  for (;;)
    {
      // Check the end loop flag. It is ok to do this without lock,
      // since we care just whether it is zero or non-zero.
      if (this->end_event_loop_ != 0)
        break;

      // <end_event_loop> is not set. Ready to do <handle_events>.
      result = this->handle_events ();

      if (eh != 0 && (*eh) (this))
        continue;

      if (result == -1)
        break;
    }

  // Leaving the event loop. Decrement the thread count.

  {
    // Obtain the lock in the MT environments.
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, mutex_, -1));

    // Decrement the thread count.
    this->event_loop_thread_count_ --;

    if (this->event_loop_thread_count_ > 0
       && this->end_event_loop_ != 0)
       this->proactor_post_wakeup_completions (1);
  }

  return result;
}

// Handle events for -tv- time.  handle_events updates -tv- to reflect
// time elapsed, so do not return until -tv- == 0, or an error occurs.
int
ACE_Proactor::proactor_run_event_loop (ACE_Time_Value &tv,
                                       PROACTOR_EVENT_HOOK eh)
{
  ACE_TRACE ("ACE_Proactor::proactor_run_event_loop");
  int result = 0;

  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, mutex_, -1));

    // Early check. It is ok to do this without lock, since we care just
    // whether it is zero or non-zero.
    if (this->end_event_loop_ != 0
       || tv == ACE_Time_Value::zero)
      return 0;

    // First time you are in. Increment the thread count.
    this->event_loop_thread_count_ ++;
  }

  // Run the event loop.
  for (;;)
    {
      // Check the end loop flag. It is ok to do this without lock,
      // since we care just whether it is zero or non-zero.
      if (this->end_event_loop_ != 0)
        break;

      // <end_event_loop> is not set. Ready to do <handle_events>.
      result = this->handle_events (tv);

      if (eh != 0 && (*eh) (this))
        continue;

      if (result == -1)
        break;

      if (tv == ACE_Time_Value::zero)
        break;
    }

  // Leaving the event loop. Decrement the thread count.

  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, mutex_, -1));

    // Decrement the thread count.
    this->event_loop_thread_count_ --;

    if (this->event_loop_thread_count_ > 0
       && this->end_event_loop_ != 0)
       this->proactor_post_wakeup_completions (1);
  }

  return result;
}

int
ACE_Proactor::proactor_reset_event_loop(void)
{
  ACE_TRACE ("ACE_Proactor::proactor_reset_event_loop");

  // Obtain the lock in the MT environments.
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, mutex_, -1));

  this->end_event_loop_ = 0;
  return 0;
}

int
ACE_Proactor::proactor_end_event_loop (void)
{
  ACE_TRACE ("ACE_Proactor::proactor_end_event_loop");

  int how_many = 0;

  {
    // Obtain the lock, set the end flag and post the wakeup
    // completions.
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, mutex_, -1));

    // Set the end flag.
    this->end_event_loop_ = 1;

    // Number of completions to post.
    how_many = this->event_loop_thread_count_;
    if (how_many == 0)
      return 0;
  }

  // Post completions to all the threads so that they will all wake
  // up.
  return this->proactor_post_wakeup_completions (how_many);
}

int
ACE_Proactor::proactor_event_loop_done (void)
{
  ACE_TRACE ("ACE_Proactor::proactor_event_loop_done");

  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, mutex_, -1));

  return this->end_event_loop_ != 0 ? 1 : 0 ;
}

int
ACE_Proactor::close (void)
{
  if (this->implementation_)
    {
      // Close the implementation.
      if (this->implementation_->close () == -1)
      ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_LIB_TEXT ("%N:%l:(%P | %t):%p\n"),
                       ACE_LIB_TEXT ("ACE_Proactor::close:implementation couldnt be closed")),
                      -1);
    }

  // Delete the implementation.
  if (this->delete_implementation_)
    {
      delete this->implementation ();
      this->implementation_ = 0;
    }

  // Delete the timer handler.
  if (this->timer_handler_)
    {
      delete this->timer_handler_;
      this->timer_handler_ = 0;
    }

  // Delete the timer queue.
  if (this->delete_timer_queue_)
    {
      delete this->timer_queue_;
      this->timer_queue_ = 0;
      this->delete_timer_queue_ = 0;
    }

  return 0;
}

int
ACE_Proactor::register_handle (ACE_HANDLE  handle,
                               const void *completion_key,
                               int         operations)
{
  if (this->implementation () == 0)
    return -1;

  return this->implementation ()->register_handle (handle,
                                                   completion_key,
                                                   operations);
}

long
ACE_Proactor::schedule_timer (ACE_Handler &handler,
                              const void *act,
                              const ACE_Time_Value &time)
{
  return this->schedule_timer (handler,
                               act,
                               time,
                               ACE_Time_Value::zero);
}

long
ACE_Proactor::schedule_repeating_timer (ACE_Handler &handler,
                                        const void *act,
                                        const ACE_Time_Value &interval)
{
  return this->schedule_timer (handler,
                               act,
                               interval,
                               interval);
}

long
ACE_Proactor::schedule_timer (ACE_Handler &handler,
                              const void *act,
                              const ACE_Time_Value &time,
                              const ACE_Time_Value &interval)
{
  // absolute time.
  ACE_Time_Value absolute_time =
    this->timer_queue_->gettimeofday () + time;

  // Only one guy goes in here at a time
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_RECURSIVE_MUTEX,
                    ace_mon,
                    this->timer_queue_->mutex (),
                    -1));

  // Schedule the timer
  long result = this->timer_queue_->schedule (&handler,
                                              act,
                                              absolute_time,
                                              interval);
  if (result != -1)
    {
      // no failures: check to see if we are the earliest time
      if (this->timer_queue_->earliest_time () == absolute_time)

        // wake up the timer thread
        if (this->timer_handler_->timer_event_.signal () == -1)
          {
            // Cancel timer
            this->timer_queue_->cancel (result);
            result = -1;
          }
    }
  return result;
}

int
ACE_Proactor::cancel_timer (long timer_id,
                            const void **arg,
                            int dont_call_handle_close)
{
  // No need to singal timer event here. Even if the cancel timer was
  // the earliest, we will have an extra wakeup.
  return this->timer_queue_->cancel (timer_id,
                                     arg,
                                     dont_call_handle_close);
}

int
ACE_Proactor::cancel_timer (ACE_Handler &handler,
                                  int dont_call_handle_close)
{
  // No need to signal timer event here. Even if the cancel timer was
  // the earliest, we will have an extra wakeup.
  return this->timer_queue_->cancel (&handler,
                                     dont_call_handle_close);
}

int
ACE_Proactor::handle_events (ACE_Time_Value &wait_time)
{
  if (this->implementation () == 0)
    return -1;

  return this->implementation ()->handle_events (wait_time);
}

int
ACE_Proactor::handle_events (void)
{
  if (this->implementation () == 0)
    return -1;

  return this->implementation ()->handle_events ();
}


ACE_Proactor::TIMER_QUEUE *
ACE_Proactor::timer_queue (void) const
{
  return this->timer_queue_;
}

void
ACE_Proactor::timer_queue (TIMER_QUEUE *tq)
{
  // Cleanup old timer queue.
  if (this->delete_timer_queue_)
    {
      delete this->timer_queue_;
      this->delete_timer_queue_ = 0;
    }

  // New timer queue.
  if (tq == 0)
    {
      ACE_NEW (this->timer_queue_,
               TIMER_HEAP);
      this->delete_timer_queue_ = 1;
    }
  else
    {
      this->timer_queue_ = tq;
      this->delete_timer_queue_ = 0;
    }

  // Set the proactor in the timer queue's functor
  this->timer_queue_->upcall_functor ().proactor (*this);
}

ACE_HANDLE
ACE_Proactor::get_handle (void) const
{
  if (this->implementation () == 0)
    return ACE_INVALID_HANDLE;

  return this->implementation ()->get_handle ();
}

ACE_Proactor_Impl *
ACE_Proactor::implementation (void) const
{
  return this->implementation_;
}


int
ACE_Proactor::proactor_post_wakeup_completions (int how_many)
{
  if (this->implementation () == 0)
    return 0;
  return this->implementation ()->post_wakeup_completions (how_many);
}

void
ACE_Proactor::implementation (ACE_Proactor_Impl *implementation)
{
  this->implementation_ = implementation;
}

int
ACE_Proactor::cancel_all_aio (void)
{ 
  if (this->implementation () == 0)
    return 2;
  return this->implementation ()->cancel_all_aio ();
}

int
ACE_Proactor::cancel_aio (ACE_Handler *handler)
{ 
  if (this->implementation () == 0)
    return 2;
  return this->implementation ()->cancel_aio (handler);
}

int
ACE_Proactor::cancel_aio (ACE_HANDLE handle)
{ 
  if (this->implementation () == 0)
    return 2;
  return this->implementation ()->cancel_aio (handle);
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Timer_Queue_T<ACE_Handler *,
  ACE_Proactor_Handle_Timeout_Upcall,
  ACE_SYNCH_RECURSIVE_MUTEX>;
template class ACE_Timer_Queue_Iterator_T<ACE_Handler *,
  ACE_Proactor_Handle_Timeout_Upcall,
  ACE_SYNCH_RECURSIVE_MUTEX>;
template class ACE_Timer_List_T<ACE_Handler *,
  ACE_Proactor_Handle_Timeout_Upcall,
  ACE_SYNCH_RECURSIVE_MUTEX>;
template class ACE_Timer_List_Iterator_T<ACE_Handler *,
  ACE_Proactor_Handle_Timeout_Upcall,
  ACE_SYNCH_RECURSIVE_MUTEX>;
template class ACE_Timer_Node_T<ACE_Handler *>;
template class ACE_Unbounded_Set<ACE_Timer_Node_T<ACE_Handler *> *>;
template class ACE_Unbounded_Set_Iterator<ACE_Timer_Node_T<ACE_Handler *> *>;
template class ACE_Node <ACE_Timer_Node_T<ACE_Handler *> *>;
template class ACE_Free_List<ACE_Timer_Node_T<ACE_Handler *> >;
template class ACE_Locked_Free_List<ACE_Timer_Node_T<ACE_Handler *>, ACE_Null_Mutex>;
template class ACE_Timer_Heap_T<ACE_Handler *,
  ACE_Proactor_Handle_Timeout_Upcall,
  ACE_SYNCH_RECURSIVE_MUTEX>;
template class ACE_Timer_Heap_Iterator_T<ACE_Handler *,
  ACE_Proactor_Handle_Timeout_Upcall,
  ACE_SYNCH_RECURSIVE_MUTEX>;
template class ACE_Timer_Wheel_T<ACE_Handler *,
  ACE_Proactor_Handle_Timeout_Upcall,
  ACE_SYNCH_RECURSIVE_MUTEX>;
template class ACE_Timer_Wheel_Iterator_T<ACE_Handler *,
  ACE_Proactor_Handle_Timeout_Upcall,
  ACE_SYNCH_RECURSIVE_MUTEX>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Timer_Queue_T<ACE_Handler *,\
  ACE_Proactor_Handle_Timeout_Upcall,\
  ACE_SYNCH_RECURSIVE_MUTEX>
#pragma instantiate ACE_Timer_Queue_Iterator_T<ACE_Handler *,\
  ACE_Proactor_Handle_Timeout_Upcall,\
  ACE_SYNCH_RECURSIVE_MUTEX>
#pragma instantiate ACE_Timer_List_T<ACE_Handler *,\
  ACE_Proactor_Handle_Timeout_Upcall,\
  ACE_SYNCH_RECURSIVE_MUTEX>
#pragma instantiate ACE_Timer_List_Iterator_T<ACE_Handler *,\
  ACE_Proactor_Handle_Timeout_Upcall,\
  ACE_SYNCH_RECURSIVE_MUTEX>
#pragma instantiate ACE_Timer_Node_T<ACE_Handler *>
#pragma instantiate ACE_Unbounded_Set<ACE_Timer_Node_T<ACE_Handler *> *>
#pragma instantiate ACE_Unbounded_Set_Iterator<ACE_Timer_Node_T<ACE_Handler *> *>
#pragma instantiate ACE_Node <ACE_Timer_Node_T<ACE_Handler *> *>
#pragma instantiate ACE_Free_List<ACE_Timer_Node_T<ACE_Handler *> >
#pragma instantiate ACE_Locked_Free_List<ACE_Timer_Node_T<ACE_Handler *>,\
   ACE_Null_Mutex>
#pragma instantiate ACE_Timer_Heap_T<ACE_Handler *,\
  ACE_Proactor_Handle_Timeout_Upcall,\
  ACE_SYNCH_RECURSIVE_MUTEX>
#pragma instantiate ACE_Timer_Heap_Iterator_T<ACE_Handler *,\
  ACE_Proactor_Handle_Timeout_Upcall,\
  ACE_SYNCH_RECURSIVE_MUTEX>
#pragma instantiate ACE_Timer_Wheel_T<ACE_Handler *,\
  ACE_Proactor_Handle_Timeout_Upcall,\
  ACE_SYNCH_RECURSIVE_MUTEX>
#pragma instantiate ACE_Timer_Wheel_Iterator_T<ACE_Handler *,\
  ACE_Proactor_Handle_Timeout_Upcall,\
  ACE_SYNCH_RECURSIVE_MUTEX>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Framework_Component_T<ACE_Proactor>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Framework_Component_T<ACE_Proactor>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

ACE_END_VERSIONED_NAMESPACE_DECL

#else /* !ACE_WIN32 || !ACE_HAS_AIO_CALLS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Proactor *
ACE_Proactor::instance (size_t threads)
{
  ACE_UNUSED_ARG (threads);
  return 0;
}

ACE_Proactor *
ACE_Proactor::instance (ACE_Proactor *)
{
  return 0;
}

void
ACE_Proactor::close_singleton (void)
{
}

int
ACE_Proactor::run_event_loop (void)
{
  // not implemented
  return -1;
}

int
ACE_Proactor::run_event_loop (ACE_Time_Value &tv)
{
  // not implemented
  ACE_UNUSED_ARG (tv);
  return -1;
}

int
ACE_Proactor::end_event_loop (void)
{
  // not implemented
  return -1;
}

sig_atomic_t
ACE_Proactor::event_loop_done (void)
{
  return sig_atomic_t (1);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_WIN32 || ACE_HAS_AIO_CALLS*/
