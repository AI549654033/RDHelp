/*
 * $Id: http.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * Copyright (c) 1994, 1995.  Netscape Communications Corporation.  All
 * rights reserved.
 *
 * Use of this software is governed by the terms of the license agreement for
 * the Netscape Communications or Netscape Comemrce Server between the
 * parties.
 */


/* ------------------------------------------------------------------------ */


/*
 * http.h: Deals with HTTP-related issues
 *
 * Rob McCool
 */


#ifndef HTTP_H
#define HTTP_H


#include "netsite.h"
#include "base/session.h"
#include "base/pblock.h"

#include "frame/req.h"               /* REQ_MAX_LINE, Request structure */

/* ------------------------------ Constants ------------------------------- */


#define HTTP_DATE_LEN 128
#define HTTP_DATE_FMT "%A, %d-%b-%y %T GMT"


/* The maximum number of RFC-822 headers we'll allow */
/* This would be smaller if a certain browser wasn't so damn stupid. */
#define HTTP_MAX_HEADERS 200

/* Whether or not we should read the headers for if-modified-since */
#define HTTP_DO_IMS
#define HTTP_ALWAYS_LOADHDRS

/* HTTP status codes */

#define PROTOCOL_OK 200
#define PROTOCOL_NO_RESPONSE 204
#define PROTOCOL_REDIRECT 302
#define PROTOCOL_NOT_MODIFIED 304
#define PROTOCOL_BAD_REQUEST 400
#define PROTOCOL_UNAUTHORIZED 401
#define PROTOCOL_FORBIDDEN 403
#define PROTOCOL_NOT_FOUND 404
#define PROTOCOL_PROXY_UNAUTHORIZED 407
#define PROTOCOL_SERVER_ERROR 500
#define PROTOCOL_NOT_IMPLEMENTED 501


#ifdef NET_SSL
#define HTTPS_PORT 443
#define HTTPS_URL "https"
#endif
#define HTTP_PORT 80
#define HTTP_URL "http"

/* -------------------------- http_scan_headers --------------------------- */


/*
 * parses the first line of an HTTP request
 */

#define protocol_parse_request http_parse_request
int http_parse_request(char *t, Request *rq, Session *sn);

/*
 * Scans HTTP headers from the given netbuf, and places them in headers.
 * If netbuf is NULL, the session's inbuf is used.
 *
 * Folded lines are joined and the linefeed removed (but not the whitespace).
 * If there are any repeat headers they are joined and the two field bodies
 * separated by a comma and space.
 *
 * t should be a string of length REQ_MAX_LINE. This is a convenience to
 * req.c so that we don't use too much runtime stack.
 *
 * Session is an optional parameter. Use NULL if you wish. It's used for
 * error logs.
 */

#define protocol_scan_headers http_scan_headers
int http_scan_headers(Session *sn, netbuf *buf, char *t, pblock *headers);


/*
 * Starts the HTTP response. If HTTP/0.9, does nothing. If 1.0, sends header.
 * If this returns REQ_NOACTION, the method was head and no body should be
 * sent. Otherwise, it will return REQ_PROCEED.
 */

#define protocol_start_response http_start_response
int http_start_response(Session *sn, Request *rq);


/*
 * http_hdrs2env takes the entries from the given pblock and converts them
 * to an environment.
 *
 * Each name entry will be made uppercase, prefixed with HTTP_ and any
 * occurrence of - will be converted to _.
 */

char **http_hdrs2env(pblock *pb);

//FUZZ: disable check_for_NULL
/*
 * http_status sets status to the code n, with reason string r. If r is
 * NULL, the server will attempt to find one for the given status code.
 * If it finds none, it will give "Because I felt like it."
 */
//FUZZ: enable check_for_NULL

#define protocol_status http_status
void http_status(Session *sn, Request *rq, int n, char *r);

/*
 * http_set_finfo sets content-length and last-modified
 */

#define protocol_set_finfo http_set_finfo
int http_set_finfo(Session *sn, Request *rq, struct stat *finfo);


/*
 * Takes the given pblock and prints headers into the given buffer at
 * position pos. Returns the buffer, reallocated if needed. Modifies pos.
 */

char *http_dump822(pblock *pb, char *t, int *pos, int tsz);

/*
 * Finishes a request. For HTTP, this just closes the socket.
 */

#define protocol_finish_request http_finish_request
void http_finish_request(Session *sn, Request *rq);


/*
 * http_handle_session processes each request generated by Session
 */

#define protocol_handle_session http_handle_session
void http_handle_session(Session *sn);

/*
 * http_uri2url takes the give URI prefix and URI suffix and creates a
 * newly-allocated full URL from them of the form
 * http://(server):(port)(prefix)(suffix)
 *
 * If you want either prefix or suffix to be skipped, use "" instead of NULL.
 */

#define protocol_uri2url http_uri2url
char *http_uri2url(char *prefix, char *suffix);

#endif
