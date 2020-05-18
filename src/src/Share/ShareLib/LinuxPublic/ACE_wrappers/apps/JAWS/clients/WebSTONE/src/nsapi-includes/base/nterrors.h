/*
 * $Id: nterrors.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * Copyright (c) 1994, 1995.  Netscape Communications Corporation.  All
 * rights reserved.
 *
 * Use of this software is governed by the terms of the license agreement for
 * the Netscape Communications or Netscape Comemrce Server between the
 * parties.
 */


/* ------------------------------------------------------------------------ */


/* DO NOT EDIT THIS FILE - it is automatically generated */

struct _NtError {
        int ErrorNumber;
        char *ErrorString;
        struct _NtError *next;
} ;

typedef struct _NtError NtError;

NtError NtErrorStrings[] = {
{ 0 , "ERROR_SUCCESS" },
{ 0 , "NO_ERROR" },
{ 1 , "ERROR_INVALID_FUNCTION" },
{ 2 , "ERROR_FILE_NOT_FOUND" },
{ 3 , "ERROR_PATH_NOT_FOUND" },
{ 4 , "ERROR_TOO_MANY_OPEN_FILES" },
{ 5 , "ERROR_ACCESS_DENIED" },
{ 6 , "ERROR_INVALID_HANDLE" },
{ 7 , "ERROR_ARENA_TRASHED" },
{ 8 , "ERROR_NOT_ENOUGH_MEMORY" },
{ 9 , "ERROR_INVALID_BLOCK" },
{ 10 , "ERROR_BAD_ENVIRONMENT" },
{ 11 , "ERROR_BAD_FORMAT" },
{ 12 , "ERROR_INVALID_ACCESS" },
{ 13 , "ERROR_INVALID_DATA" },
{ 14 , "ERROR_OUTOFMEMORY" },
{ 15 , "ERROR_INVALID_DRIVE" },
{ 16 , "ERROR_CURRENT_DIRECTORY" },
{ 17 , "ERROR_NOT_SAME_DEVICE" },
{ 18 , "ERROR_NO_MORE_FILES" },
{ 19 , "ERROR_WRITE_PROTECT" },
{ 20 , "ERROR_BAD_UNIT" },
{ 21 , "ERROR_NOT_READY" },
{ 22 , "ERROR_BAD_COMMAND" },
{ 23 , "ERROR_CRC" },
{ 24 , "ERROR_BAD_LENGTH" },
{ 25 , "ERROR_SEEK" },
{ 26 , "ERROR_NOT_DOS_DISK" },
{ 27 , "ERROR_SECTOR_NOT_FOUND" },
{ 28 , "ERROR_OUT_OF_PAPER" },
{ 29 , "ERROR_WRITE_FAULT" },
{ 30 , "ERROR_READ_FAULT" },
{ 31 , "ERROR_GEN_FAILURE" },
{ 32 , "ERROR_SHARING_VIOLATION" },
{ 33 , "ERROR_LOCK_VIOLATION" },
{ 34 , "ERROR_WRONG_DISK" },
{ 36 , "ERROR_SHARING_BUFFER_EXCEEDED" },
{ 38 , "ERROR_HANDLE_EOF" },
{ 39 , "ERROR_HANDLE_DISK_FULL" },
{ 50 , "ERROR_NOT_SUPPORTED" },
{ 51 , "ERROR_REM_NOT_LIST" },
{ 52 , "ERROR_DUP_NAME" },
{ 53 , "ERROR_BAD_NETPATH" },
{ 54 , "ERROR_NETWORK_BUSY" },
{ 55 , "ERROR_DEV_NOT_EXIST" },
{ 56 , "ERROR_TOO_MANY_CMDS" },
{ 57 , "ERROR_ADAP_HDW_ERR" },
{ 58 , "ERROR_BAD_NET_RESP" },
{ 59 , "ERROR_UNEXP_NET_ERR" },
{ 60 , "ERROR_BAD_REM_ADAP" },
{ 61 , "ERROR_PRINTQ_FULL" },
{ 62 , "ERROR_NO_SPOOL_SPACE" },
{ 63 , "ERROR_PRINT_CANCELLED" },
{ 64 , "ERROR_NETNAME_DELETED" },
{ 65 , "ERROR_NETWORK_ACCESS_DENIED" },
{ 66 , "ERROR_BAD_DEV_TYPE" },
{ 67 , "ERROR_BAD_NET_NAME" },
{ 68 , "ERROR_TOO_MANY_NAMES" },
{ 69 , "ERROR_TOO_MANY_SESS" },
{ 70 , "ERROR_SHARING_PAUSED" },
{ 71 , "ERROR_REQ_NOT_ACCEP" },
{ 72 , "ERROR_REDIR_PAUSED" },
{ 80 , "ERROR_FILE_EXISTS" },
{ 82 , "ERROR_CANNOT_MAKE" },
{ 83 , "ERROR_FAIL_I24" },
{ 84 , "ERROR_OUT_OF_STRUCTURES" },
{ 85 , "ERROR_ALREADY_ASSIGNED" },
{ 86 , "ERROR_INVALID_PASSWORD" },
{ 87 , "ERROR_INVALID_PARAMETER" },
{ 88 , "ERROR_NET_WRITE_FAULT" },
{ 89 , "ERROR_NO_PROC_SLOTS" },
{ 100 , "ERROR_TOO_MANY_SEMAPHORES" },
{ 101 , "ERROR_EXCL_SEM_ALREADY_OWNED" },
{ 102 , "ERROR_SEM_IS_SET" },
{ 103 , "ERROR_TOO_MANY_SEM_REQUESTS" },
{ 104 , "ERROR_INVALID_AT_INTERRUPT_TIME" },
{ 105 , "ERROR_SEM_OWNER_DIED" },
{ 106 , "ERROR_SEM_USER_LIMIT" },
{ 107 , "ERROR_DISK_CHANGE" },
{ 108 , "ERROR_DRIVE_LOCKED" },
{ 109 , "ERROR_BROKEN_PIPE" },
{ 110 , "ERROR_OPEN_FAILED" },
{ 111 , "ERROR_BUFFER_OVERFLOW" },
{ 112 , "ERROR_DISK_FULL" },
{ 113 , "ERROR_NO_MORE_SEARCH_HANDLES" },
{ 114 , "ERROR_INVALID_TARGET_HANDLE" },
{ 117 , "ERROR_INVALID_CATEGORY" },
{ 118 , "ERROR_INVALID_VERIFY_SWITCH" },
{ 119 , "ERROR_BAD_DRIVER_LEVEL" },
{ 120 , "ERROR_CALL_NOT_IMPLEMENTED" },
{ 121 , "ERROR_SEM_TIMEOUT" },
{ 122 , "ERROR_INSUFFICIENT_BUFFER" },
{ 123 , "ERROR_INVALID_NAME" },
{ 124 , "ERROR_INVALID_LEVEL" },
{ 125 , "ERROR_NO_VOLUME_LABEL" },
{ 126 , "ERROR_MOD_NOT_FOUND" },
{ 127 , "ERROR_PROC_NOT_FOUND" },
{ 128 , "ERROR_WAIT_NO_CHILDREN" },
{ 129 , "ERROR_CHILD_NOT_COMPLETE" },
{ 130 , "ERROR_DIRECT_ACCESS_HANDLE" },
{ 131 , "ERROR_NEGATIVE_SEEK" },
{ 132 , "ERROR_SEEK_ON_DEVICE" },
{ 133 , "ERROR_IS_JOIN_TARGET" },
{ 134 , "ERROR_IS_JOINED" },
{ 135 , "ERROR_IS_SUBSTED" },
{ 136 , "ERROR_NOT_JOINED" },
{ 137 , "ERROR_NOT_SUBSTED" },
{ 138 , "ERROR_JOIN_TO_JOIN" },
{ 139 , "ERROR_SUBST_TO_SUBST" },
{ 140 , "ERROR_JOIN_TO_SUBST" },
{ 141 , "ERROR_SUBST_TO_JOIN" },
{ 142 , "ERROR_BUSY_DRIVE" },
{ 143 , "ERROR_SAME_DRIVE" },
{ 144 , "ERROR_DIR_NOT_ROOT" },
{ 145 , "ERROR_DIR_NOT_EMPTY" },
{ 146 , "ERROR_IS_SUBST_PATH" },
{ 147 , "ERROR_IS_JOIN_PATH" },
{ 148 , "ERROR_PATH_BUSY" },
{ 149 , "ERROR_IS_SUBST_TARGET" },
{ 150 , "ERROR_SYSTEM_TRACE" },
{ 151 , "ERROR_INVALID_EVENT_COUNT" },
{ 152 , "ERROR_TOO_MANY_MUXWAITERS" },
{ 153 , "ERROR_INVALID_LIST_FORMAT" },
{ 154 , "ERROR_LABEL_TOO_LONG" },
{ 155 , "ERROR_TOO_MANY_TCBS" },
{ 156 , "ERROR_SIGNAL_REFUSED" },
{ 157 , "ERROR_DISCARDED" },
{ 158 , "ERROR_NOT_LOCKED" },
{ 159 , "ERROR_BAD_THREADID_ADDR" },
{ 160 , "ERROR_BAD_ARGUMENTS" },
{ 161 , "ERROR_BAD_PATHNAME" },
{ 162 , "ERROR_SIGNAL_PENDING" },
{ 164 , "ERROR_MAX_THRDS_REACHED" },
{ 167 , "ERROR_LOCK_FAILED" },
{ 170 , "ERROR_BUSY" },
{ 173 , "ERROR_CANCEL_VIOLATION" },
{ 174 , "ERROR_ATOMIC_LOCKS_NOT_SUPPORTED" },
{ 180 , "ERROR_INVALID_SEGMENT_NUMBER" },
{ 182 , "ERROR_INVALID_ORDINAL" },
{ 183 , "ERROR_ALREADY_EXISTS" },
{ 186 , "ERROR_INVALID_FLAG_NUMBER" },
{ 187 , "ERROR_SEM_NOT_FOUND" },
{ 188 , "ERROR_INVALID_STARTING_CODESEG" },
{ 189 , "ERROR_INVALID_STACKSEG" },
{ 190 , "ERROR_INVALID_MODULETYPE" },
{ 191 , "ERROR_INVALID_EXE_SIGNATURE" },
{ 192 , "ERROR_EXE_MARKED_INVALID" },
{ 193 , "ERROR_BAD_EXE_FORMAT" },
{ 194 , "ERROR_ITERATED_DATA_EXCEEDS_64k" },
{ 195 , "ERROR_INVALID_MINALLOCSIZE" },
{ 196 , "ERROR_DYNLINK_FROM_INVALID_RING" },
{ 197 , "ERROR_IOPL_NOT_ENABLED" },
{ 198 , "ERROR_INVALID_SEGDPL" },
{ 199 , "ERROR_AUTODATASEG_EXCEEDS_64k" },
{ 200 , "ERROR_RING2SEG_MUST_BE_MOVABLE" },
{ 201 , "ERROR_RELOC_CHAIN_XEEDS_SEGLIM" },
{ 202 , "ERROR_INFLOOP_IN_RELOC_CHAIN" },
{ 203 , "ERROR_ENVVAR_NOT_FOUND" },
{ 205 , "ERROR_NO_SIGNAL_SENT" },
{ 206 , "ERROR_FILENAME_EXCED_RANGE" },
{ 207 , "ERROR_RING2_STACK_IN_USE" },
{ 208 , "ERROR_META_EXPANSION_TOO_LONG" },
{ 209 , "ERROR_INVALID_SIGNAL_NUMBER" },
{ 210 , "ERROR_THREAD_1_INACTIVE" },
{ 212 , "ERROR_LOCKED" },
{ 214 , "ERROR_TOO_MANY_MODULES" },
{ 215 , "ERROR_NESTING_NOT_ALLOWED" },
{ 230 , "ERROR_BAD_PIPE" },
{ 231 , "ERROR_PIPE_BUSY" },
{ 232 , "ERROR_NO_DATA" },
{ 233 , "ERROR_PIPE_NOT_CONNECTED" },
{ 234 , "ERROR_MORE_DATA" },
{ 240 , "ERROR_VC_DISCONNECTED" },
{ 254 , "ERROR_INVALID_EA_NAME" },
{ 255 , "ERROR_EA_LIST_INCONSISTENT" },
{ 259 , "ERROR_NO_MORE_ITEMS" },
{ 266 , "ERROR_CANNOT_COPY" },
{ 267 , "ERROR_DIRECTORY" },
{ 275 , "ERROR_EAS_DIDNT_FIT" },
{ 276 , "ERROR_EA_FILE_CORRUPT" },
{ 277 , "ERROR_EA_TABLE_FULL" },
{ 278 , "ERROR_INVALID_EA_HANDLE" },
{ 282 , "ERROR_EAS_NOT_SUPPORTED" },
{ 288 , "ERROR_NOT_OWNER" },
{ 298 , "ERROR_TOO_MANY_POSTS" },
{ 299 , "ERROR_PARTIAL_COPY" },
{ 317 , "ERROR_MR_MID_NOT_FOUND" },
{ 487 , "ERROR_INVALID_ADDRESS" },
{ 534 , "ERROR_ARITHMETIC_OVERFLOW" },
{ 535 , "ERROR_PIPE_CONNECTED" },
{ 536 , "ERROR_PIPE_LISTENING" },
{ 994 , "ERROR_EA_ACCESS_DENIED" },
{ 995 , "ERROR_OPERATION_ABORTED" },
{ 996 , "ERROR_IO_INCOMPLETE" },
{ 997 , "ERROR_IO_PENDING" },
{ 998 , "ERROR_NOACCESS" },
{ 999 , "ERROR_SWAPERROR" },
{ 1001 , "ERROR_STACK_OVERFLOW" },
{ 1002 , "ERROR_INVALID_MESSAGE" },
{ 1003 , "ERROR_CAN_NOT_COMPLETE" },
{ 1004 , "ERROR_INVALID_FLAGS" },
{ 1005 , "ERROR_UNRECOGNIZED_VOLUME" },
{ 1006 , "ERROR_FILE_INVALID" },
{ 1007 , "ERROR_FULLSCREEN_MODE" },
{ 1008 , "ERROR_NO_TOKEN" },
{ 1009 , "ERROR_BADDB" },
{ 1010 , "ERROR_BADKEY" },
{ 1011 , "ERROR_CANTOPEN" },
{ 1012 , "ERROR_CANTREAD" },
{ 1013 , "ERROR_CANTWRITE" },
{ 1014 , "ERROR_REGISTRY_RECOVERED" },
{ 1015 , "ERROR_REGISTRY_CORRUPT" },
{ 1016 , "ERROR_REGISTRY_IO_FAILED" },
{ 1017 , "ERROR_NOT_REGISTRY_FILE" },
{ 1018 , "ERROR_KEY_DELETED" },
{ 1019 , "ERROR_NO_LOG_SPACE" },
{ 1020 , "ERROR_KEY_HAS_CHILDREN" },
{ 1021 , "ERROR_CHILD_MUST_BE_VOLATILE" },
{ 1022 , "ERROR_NOTIFY_ENUM_DIR" },
{ 1051 , "ERROR_DEPENDENT_SERVICES_RUNNING" },
{ 1052 , "ERROR_INVALID_SERVICE_CONTROL" },
{ 1053 , "ERROR_SERVICE_REQUEST_TIMEOUT" },
{ 1054 , "ERROR_SERVICE_NO_THREAD" },
{ 1055 , "ERROR_SERVICE_DATABASE_LOCKED" },
{ 1056 , "ERROR_SERVICE_ALREADY_RUNNING" },
{ 1057 , "ERROR_INVALID_SERVICE_ACCOUNT" },
{ 1058 , "ERROR_SERVICE_DISABLED" },
{ 1059 , "ERROR_CIRCULAR_DEPENDENCY" },
{ 1060 , "ERROR_SERVICE_DOES_NOT_EXIST" },
{ 1061 , "ERROR_SERVICE_CANNOT_ACCEPT_CTRL" },
{ 1062 , "ERROR_SERVICE_NOT_ACTIVE" },
{ 1063 , "ERROR_FAILED_SERVICE_CONTROLLER_CONNECT" },
{ 1064 , "ERROR_EXCEPTION_IN_SERVICE" },
{ 1065 , "ERROR_DATABASE_DOES_NOT_EXIST" },
{ 1066 , "ERROR_SERVICE_SPECIFIC_ERROR" },
{ 1067 , "ERROR_PROCESS_ABORTED" },
{ 1068 , "ERROR_SERVICE_DEPENDENCY_FAIL" },
{ 1069 , "ERROR_SERVICE_LOGON_FAILED" },
{ 1070 , "ERROR_SERVICE_START_HANG" },
{ 1071 , "ERROR_INVALID_SERVICE_LOCK" },
{ 1072 , "ERROR_SERVICE_MARKED_FOR_DELETE" },
{ 1073 , "ERROR_SERVICE_EXISTS" },
{ 1074 , "ERROR_ALREADY_RUNNING_LKG" },
{ 1075 , "ERROR_SERVICE_DEPENDENCY_DELETED" },
{ 1076 , "ERROR_BOOT_ALREADY_ACCEPTED" },
{ 1077 , "ERROR_SERVICE_NEVER_STARTED" },
{ 1078 , "ERROR_DUPLICATE_SERVICE_NAME" },
{ 1100 , "ERROR_END_OF_MEDIA" },
{ 1101 , "ERROR_FILEMARK_DETECTED" },
{ 1102 , "ERROR_BEGINNING_OF_MEDIA" },
{ 1103 , "ERROR_SETMARK_DETECTED" },
{ 1104 , "ERROR_NO_DATA_DETECTED" },
{ 1105 , "ERROR_PARTITION_FAILURE" },
{ 1106 , "ERROR_INVALID_BLOCK_LENGTH" },
{ 1107 , "ERROR_DEVICE_NOT_PARTITIONED" },
{ 1108 , "ERROR_UNABLE_TO_LOCK_MEDIA" },
{ 1109 , "ERROR_UNABLE_TO_UNLOAD_MEDIA" },
{ 1110 , "ERROR_MEDIA_CHANGED" },
{ 1111 , "ERROR_BUS_RESET" },
{ 1112 , "ERROR_NO_MEDIA_IN_DRIVE" },
{ 1113 , "ERROR_NO_UNICODE_TRANSLATION" },
{ 1114 , "ERROR_DLL_INIT_FAILED" },
{ 1115 , "ERROR_SHUTDOWN_IN_PROGRESS" },
{ 1116 , "ERROR_NO_SHUTDOWN_IN_PROGRESS" },
{ 1117 , "ERROR_IO_DEVICE" },
{ 1118 , "ERROR_SERIAL_NO_DEVICE" },
{ 1119 , "ERROR_IRQ_BUSY" },
{ 1120 , "ERROR_MORE_WRITES" },
{ 1121 , "ERROR_COUNTER_TIMEOUT" },
{ 1122 , "ERROR_FLOPPY_ID_MARK_NOT_FOUND" },
{ 1123 , "ERROR_FLOPPY_WRONG_CYLINDER" },
{ 1124 , "ERROR_FLOPPY_UNKNOWN_ERROR" },
{ 1125 , "ERROR_FLOPPY_BAD_REGISTERS" },
{ 1126 , "ERROR_DISK_RECALIBRATE_FAILED" },
{ 1127 , "ERROR_DISK_OPERATION_FAILED" },
{ 1128 , "ERROR_DISK_RESET_FAILED" },
{ 1129 , "ERROR_EOM_OVERFLOW" },
{ 1130 , "ERROR_NOT_ENOUGH_SERVER_MEMORY" },
{ 1131 , "ERROR_POSSIBLE_DEADLOCK" },
{ 1132 , "ERROR_MAPPED_ALIGNMENT" },
{ 1140 , "ERROR_SET_POWER_STATE_VETOED" },
{ 1141 , "ERROR_SET_POWER_STATE_FAILED" },
{ 1150 , "ERROR_OLD_WIN_VERSION" },
{ 1151 , "ERROR_APP_WRONG_OS" },
{ 1152 , "ERROR_SINGLE_INSTANCE_APP" },
{ 1153 , "ERROR_RMODE_APP" },
{ 1154 , "ERROR_INVALID_DLL" },
{ 1155 , "ERROR_NO_ASSOCIATION" },
{ 1156 , "ERROR_DDE_FAIL" },
{ 1157 , "ERROR_DLL_NOT_FOUND" },
{ 2202 , "ERROR_BAD_USERNAME" },
{ 2250 , "ERROR_NOT_CONNECTED" },
{ 2401 , "ERROR_OPEN_FILES" },
{ 2402 , "ERROR_ACTIVE_CONNECTIONS" },
{ 2404 , "ERROR_DEVICE_IN_USE" },
{ 1200 , "ERROR_BAD_DEVICE" },
{ 1201 , "ERROR_CONNECTION_UNAVAIL" },
{ 1202 , "ERROR_DEVICE_ALREADY_REMEMBERED" },
{ 1203 , "ERROR_NO_NET_OR_BAD_PATH" },
{ 1204 , "ERROR_BAD_PROVIDER" },
{ 1205 , "ERROR_CANNOT_OPEN_PROFILE" },
{ 1206 , "ERROR_BAD_PROFILE" },
{ 1207 , "ERROR_NOT_CONTAINER" },
{ 1208 , "ERROR_EXTENDED_ERROR" },
{ 1209 , "ERROR_INVALID_GROUPNAME" },
{ 1210 , "ERROR_INVALID_COMPUTERNAME" },
{ 1211 , "ERROR_INVALID_EVENTNAME" },
{ 1212 , "ERROR_INVALID_DOMAINNAME" },
{ 1213 , "ERROR_INVALID_SERVICENAME" },
{ 1214 , "ERROR_INVALID_NETNAME" },
{ 1215 , "ERROR_INVALID_SHARENAME" },
{ 1216 , "ERROR_INVALID_PASSWORDNAME" },
{ 1217 , "ERROR_INVALID_MESSAGENAME" },
{ 1218 , "ERROR_INVALID_MESSAGEDEST" },
{ 1219 , "ERROR_SESSION_CREDENTIAL_CONFLICT" },
{ 1220 , "ERROR_REMOTE_SESSION_LIMIT_EXCEEDED" },
{ 1221 , "ERROR_DUP_DOMAINNAME" },
{ 1222 , "ERROR_NO_NETWORK" },
{ 1223 , "ERROR_CANCELLED" },
{ 1224 , "ERROR_USER_MAPPED_FILE" },
{ 1225 , "ERROR_CONNECTION_REFUSED" },
{ 1226 , "ERROR_GRACEFUL_DISCONNECT" },
{ 1227 , "ERROR_ADDRESS_ALREADY_ASSOCIATED" },
{ 1228 , "ERROR_ADDRESS_NOT_ASSOCIATED" },
{ 1229 , "ERROR_CONNECTION_INVALID" },
{ 1230 , "ERROR_CONNECTION_ACTIVE" },
{ 1231 , "ERROR_NETWORK_UNREACHABLE" },
{ 1232 , "ERROR_HOST_UNREACHABLE" },
{ 1233 , "ERROR_PROTOCOL_UNREACHABLE" },
{ 1234 , "ERROR_PORT_UNREACHABLE" },
{ 1235 , "ERROR_REQUEST_ABORTED" },
{ 1236 , "ERROR_CONNECTION_ABORTED" },
{ 1237 , "ERROR_RETRY" },
{ 1238 , "ERROR_CONNECTION_COUNT_LIMIT" },
{ 1239 , "ERROR_LOGIN_TIME_RESTRICTION" },
{ 1240 , "ERROR_LOGIN_WKSTA_RESTRICTION" },
{ 1241 , "ERROR_INCORRECT_ADDRESS" },
{ 1242 , "ERROR_ALREADY_REGISTERED" },
{ 1243 , "ERROR_SERVICE_NOT_FOUND" },
{ 1244 , "ERROR_NOT_AUTHENTICATED" },
{ 1245 , "ERROR_NOT_LOGGED_ON" },
{ 1246 , "ERROR_CONTINUE" },
{ 1247 , "ERROR_ALREADY_INITIALIZED" },
{ 1248 , "ERROR_NO_MORE_DEVICES" },
{ 1300 , "ERROR_NOT_ALL_ASSIGNED" },
{ 1301 , "ERROR_SOME_NOT_MAPPED" },
{ 1302 , "ERROR_NO_QUOTAS_FOR_ACCOUNT" },
{ 1303 , "ERROR_LOCAL_USER_SESSION_KEY" },
{ 1304 , "ERROR_NULL_LM_PASSWORD" },
{ 1305 , "ERROR_UNKNOWN_REVISION" },
{ 1306 , "ERROR_REVISION_MISMATCH" },
{ 1307 , "ERROR_INVALID_OWNER" },
{ 1308 , "ERROR_INVALID_PRIMARY_GROUP" },
{ 1309 , "ERROR_NO_IMPERSONATION_TOKEN" },
{ 1310 , "ERROR_CANT_DISABLE_MANDATORY" },
{ 1311 , "ERROR_NO_LOGON_SERVERS" },
{ 1312 , "ERROR_NO_SUCH_LOGON_SESSION" },
{ 1313 , "ERROR_NO_SUCH_PRIVILEGE" },
{ 1314 , "ERROR_PRIVILEGE_NOT_HELD" },
{ 1315 , "ERROR_INVALID_ACCOUNT_NAME" },
{ 1316 , "ERROR_USER_EXISTS" },
{ 1317 , "ERROR_NO_SUCH_USER" },
{ 1318 , "ERROR_GROUP_EXISTS" },
{ 1319 , "ERROR_NO_SUCH_GROUP" },
{ 1320 , "ERROR_MEMBER_IN_GROUP" },
{ 1321 , "ERROR_MEMBER_NOT_IN_GROUP" },
{ 1322 , "ERROR_LAST_ADMIN" },
{ 1323 , "ERROR_WRONG_PASSWORD" },
{ 1324 , "ERROR_ILL_FORMED_PASSWORD" },
{ 1325 , "ERROR_PASSWORD_RESTRICTION" },
{ 1326 , "ERROR_LOGON_FAILURE" },
{ 1327 , "ERROR_ACCOUNT_RESTRICTION" },
{ 1328 , "ERROR_INVALID_LOGON_HOURS" },
{ 1329 , "ERROR_INVALID_WORKSTATION" },
{ 1330 , "ERROR_PASSWORD_EXPIRED" },
{ 1331 , "ERROR_ACCOUNT_DISABLED" },
{ 1332 , "ERROR_NONE_MAPPED" },
{ 1333 , "ERROR_TOO_MANY_LUIDS_REQUESTED" },
{ 1334 , "ERROR_LUIDS_EXHAUSTED" },
{ 1335 , "ERROR_INVALID_SUB_AUTHORITY" },
{ 1336 , "ERROR_INVALID_ACL" },
{ 1337 , "ERROR_INVALID_SID" },
{ 1338 , "ERROR_INVALID_SECURITY_DESCR" },
{ 1340 , "ERROR_BAD_INHERITANCE_ACL" },
{ 1341 , "ERROR_SERVER_DISABLED" },
{ 1342 , "ERROR_SERVER_NOT_DISABLED" },
{ 1343 , "ERROR_INVALID_ID_AUTHORITY" },
{ 1344 , "ERROR_ALLOTTED_SPACE_EXCEEDED" },
{ 1345 , "ERROR_INVALID_GROUP_ATTRIBUTES" },
{ 1346 , "ERROR_BAD_IMPERSONATION_LEVEL" },
{ 1347 , "ERROR_CANT_OPEN_ANONYMOUS" },
{ 1348 , "ERROR_BAD_VALIDATION_CLASS" },
{ 1349 , "ERROR_BAD_TOKEN_TYPE" },
{ 1350 , "ERROR_NO_SECURITY_ON_OBJECT" },
{ 1351 , "ERROR_CANT_ACCESS_DOMAIN_INFO" },
{ 1352 , "ERROR_INVALID_SERVER_STATE" },
{ 1353 , "ERROR_INVALID_DOMAIN_STATE" },
{ 1354 , "ERROR_INVALID_DOMAIN_ROLE" },
{ 1355 , "ERROR_NO_SUCH_DOMAIN" },
{ 1356 , "ERROR_DOMAIN_EXISTS" },
{ 1357 , "ERROR_DOMAIN_LIMIT_EXCEEDED" },
{ 1358 , "ERROR_INTERNAL_DB_CORRUPTION" },
{ 1359 , "ERROR_INTERNAL_ERROR" },
{ 1360 , "ERROR_GENERIC_NOT_MAPPED" },
{ 1361 , "ERROR_BAD_DESCRIPTOR_FORMAT" },
{ 1362 , "ERROR_NOT_LOGON_PROCESS" },
{ 1363 , "ERROR_LOGON_SESSION_EXISTS" },
{ 1364 , "ERROR_NO_SUCH_PACKAGE" },
{ 1365 , "ERROR_BAD_LOGON_SESSION_STATE" },
{ 1366 , "ERROR_LOGON_SESSION_COLLISION" },
{ 1367 , "ERROR_INVALID_LOGON_TYPE" },
{ 1368 , "ERROR_CANNOT_IMPERSONATE" },
{ 1369 , "ERROR_RXACT_INVALID_STATE" },
{ 1370 , "ERROR_RXACT_COMMIT_FAILURE" },
{ 1371 , "ERROR_SPECIAL_ACCOUNT" },
{ 1372 , "ERROR_SPECIAL_GROUP" },
{ 1373 , "ERROR_SPECIAL_USER" },
{ 1374 , "ERROR_MEMBERS_PRIMARY_GROUP" },
{ 1375 , "ERROR_TOKEN_ALREADY_IN_USE" },
{ 1376 , "ERROR_NO_SUCH_ALIAS" },
{ 1377 , "ERROR_MEMBER_NOT_IN_ALIAS" },
{ 1378 , "ERROR_MEMBER_IN_ALIAS" },
{ 1379 , "ERROR_ALIAS_EXISTS" },
{ 1380 , "ERROR_LOGON_NOT_GRANTED" },
{ 1381 , "ERROR_TOO_MANY_SECRETS" },
{ 1382 , "ERROR_SECRET_TOO_LONG" },
{ 1383 , "ERROR_INTERNAL_DB_ERROR" },
{ 1384 , "ERROR_TOO_MANY_CONTEXT_IDS" },
{ 1385 , "ERROR_LOGON_TYPE_NOT_GRANTED" },
{ 1386 , "ERROR_NT_CROSS_ENCRYPTION_REQUIRED" },
{ 1387 , "ERROR_NO_SUCH_MEMBER" },
{ 1388 , "ERROR_INVALID_MEMBER" },
{ 1389 , "ERROR_TOO_MANY_SIDS" },
{ 1390 , "ERROR_LM_CROSS_ENCRYPTION_REQUIRED" },
{ 1391 , "ERROR_NO_INHERITANCE" },
{ 1392 , "ERROR_FILE_CORRUPT" },
{ 1393 , "ERROR_DISK_CORRUPT" },
{ 1394 , "ERROR_NO_USER_SESSION_KEY" },
{ 1395 , "ERROR_LICENSE_QUOTA_EXCEEDED" },
{ 1400 , "ERROR_INVALID_WINDOW_HANDLE" },
{ 1401 , "ERROR_INVALID_MENU_HANDLE" },
{ 1402 , "ERROR_INVALID_CURSOR_HANDLE" },
{ 1403 , "ERROR_INVALID_ACCEL_HANDLE" },
{ 1404 , "ERROR_INVALID_HOOK_HANDLE" },
{ 1405 , "ERROR_INVALID_DWP_HANDLE" },
{ 1406 , "ERROR_TLW_WITH_WSCHILD" },
{ 1407 , "ERROR_CANNOT_FIND_WND_CLASS" },
{ 1408 , "ERROR_WINDOW_OF_OTHER_THREAD" },
{ 1409 , "ERROR_HOTKEY_ALREADY_REGISTERED" },
{ 1410 , "ERROR_CLASS_ALREADY_EXISTS" },
{ 1411 , "ERROR_CLASS_DOES_NOT_EXIST" },
{ 1412 , "ERROR_CLASS_HAS_WINDOWS" },
{ 1413 , "ERROR_INVALID_INDEX" },
{ 1414 , "ERROR_INVALID_ICON_HANDLE" },
{ 1415 , "ERROR_PRIVATE_DIALOG_INDEX" },
{ 1416 , "ERROR_LISTBOX_ID_NOT_FOUND" },
{ 1417 , "ERROR_NO_WILDCARD_CHARACTERS" },
{ 1418 , "ERROR_CLIPBOARD_NOT_OPEN" },
{ 1419 , "ERROR_HOTKEY_NOT_REGISTERED" },
{ 1420 , "ERROR_WINDOW_NOT_DIALOG" },
{ 1421 , "ERROR_CONTROL_ID_NOT_FOUND" },
{ 1422 , "ERROR_INVALID_COMBOBOX_MESSAGE" },
{ 1423 , "ERROR_WINDOW_NOT_COMBOBOX" },
{ 1424 , "ERROR_INVALID_EDIT_HEIGHT" },
{ 1425 , "ERROR_DC_NOT_FOUND" },
{ 1426 , "ERROR_INVALID_HOOK_FILTER" },
{ 1427 , "ERROR_INVALID_FILTER_PROC" },
{ 1428 , "ERROR_HOOK_NEEDS_HMOD" },
{ 1429 , "ERROR_GLOBAL_ONLY_HOOK" },
{ 1430 , "ERROR_JOURNAL_HOOK_SET" },
{ 1431 , "ERROR_HOOK_NOT_INSTALLED" },
{ 1432 , "ERROR_INVALID_LB_MESSAGE" },
{ 1433 , "ERROR_SETCOUNT_ON_BAD_LB" },
{ 1434 , "ERROR_LB_WITHOUT_TABSTOPS" },
{ 1435 , "ERROR_DESTROY_OBJECT_OF_OTHER_THREAD" },
{ 1436 , "ERROR_CHILD_WINDOW_MENU" },
{ 1437 , "ERROR_NO_SYSTEM_MENU" },
{ 1438 , "ERROR_INVALID_MSGBOX_STYLE" },
{ 1439 , "ERROR_INVALID_SPI_VALUE" },
{ 1440 , "ERROR_SCREEN_ALREADY_LOCKED" },
{ 1441 , "ERROR_HWNDS_HAVE_DIFF_PARENT" },
{ 1442 , "ERROR_NOT_CHILD_WINDOW" },
{ 1443 , "ERROR_INVALID_GW_COMMAND" },
{ 1444 , "ERROR_INVALID_THREAD_ID" },
{ 1445 , "ERROR_NON_MDICHILD_WINDOW" },
{ 1446 , "ERROR_POPUP_ALREADY_ACTIVE" },
{ 1447 , "ERROR_NO_SCROLLBARS" },
{ 1448 , "ERROR_INVALID_SCROLLBAR_RANGE" },
{ 1449 , "ERROR_INVALID_SHOWWIN_COMMAND" },
{ 1450 , "ERROR_NO_SYSTEM_RESOURCES" },
{ 1451 , "ERROR_NONPAGED_SYSTEM_RESOURCES" },
{ 1452 , "ERROR_PAGED_SYSTEM_RESOURCES" },
{ 1453 , "ERROR_WORKING_SET_QUOTA" },
{ 1454 , "ERROR_PAGEFILE_QUOTA" },
{ 1455 , "ERROR_COMMITMENT_LIMIT" },
{ 1456 , "ERROR_MENU_ITEM_NOT_FOUND" },
{ 1500 , "ERROR_EVENTLOG_FILE_CORRUPT" },
{ 1501 , "ERROR_EVENTLOG_CANT_START" },
{ 1502 , "ERROR_LOG_FILE_FULL" },
{ 1503 , "ERROR_EVENTLOG_FILE_CHANGED" },
{ 1700 , "RPC_S_INVALID_STRING_BINDING" },
{ 1701 , "RPC_S_WRONG_KIND_OF_BINDING" },
{ 1702 , "RPC_S_INVALID_BINDING" },
{ 1703 , "RPC_S_PROTSEQ_NOT_SUPPORTED" },
{ 1704 , "RPC_S_INVALID_RPC_PROTSEQ" },
{ 1705 , "RPC_S_INVALID_STRING_UUID" },
{ 1706 , "RPC_S_INVALID_ENDPOINT_FORMAT" },
{ 1707 , "RPC_S_INVALID_NET_ADDR" },
{ 1708 , "RPC_S_NO_ENDPOINT_FOUND" },
{ 1709 , "RPC_S_INVALID_TIMEOUT" },
{ 1710 , "RPC_S_OBJECT_NOT_FOUND" },
{ 1711 , "RPC_S_ALREADY_REGISTERED" },
{ 1712 , "RPC_S_TYPE_ALREADY_REGISTERED" },
{ 1713 , "RPC_S_ALREADY_LISTENING" },
{ 1714 , "RPC_S_NO_PROTSEQS_REGISTERED" },
{ 1715 , "RPC_S_NOT_LISTENING" },
{ 1716 , "RPC_S_UNKNOWN_MGR_TYPE" },
{ 1717 , "RPC_S_UNKNOWN_IF" },
{ 1718 , "RPC_S_NO_BINDINGS" },
{ 1719 , "RPC_S_NO_PROTSEQS" },
{ 1720 , "RPC_S_CANT_CREATE_ENDPOINT" },
{ 1721 , "RPC_S_OUT_OF_RESOURCES" },
{ 1722 , "RPC_S_SERVER_UNAVAILABLE" },
{ 1723 , "RPC_S_SERVER_TOO_BUSY" },
{ 1724 , "RPC_S_INVALID_NETWORK_OPTIONS" },
{ 1725 , "RPC_S_NO_CALL_ACTIVE" },
{ 1726 , "RPC_S_CALL_FAILED" },
{ 1727 , "RPC_S_CALL_FAILED_DNE" },
{ 1728 , "RPC_S_PROTOCOL_ERROR" },
{ 1730 , "RPC_S_UNSUPPORTED_TRANS_SYN" },
{ 1732 , "RPC_S_UNSUPPORTED_TYPE" },
{ 1733 , "RPC_S_INVALID_TAG" },
{ 1734 , "RPC_S_INVALID_BOUND" },
{ 1735 , "RPC_S_NO_ENTRY_NAME" },
{ 1736 , "RPC_S_INVALID_NAME_SYNTAX" },
{ 1737 , "RPC_S_UNSUPPORTED_NAME_SYNTAX" },
{ 1739 , "RPC_S_UUID_NO_ADDRESS" },
{ 1740 , "RPC_S_DUPLICATE_ENDPOINT" },
{ 1741 , "RPC_S_UNKNOWN_AUTHN_TYPE" },
{ 1742 , "RPC_S_MAX_CALLS_TOO_SMALL" },
{ 1743 , "RPC_S_STRING_TOO_LONG" },
{ 1744 , "RPC_S_PROTSEQ_NOT_FOUND" },
{ 1745 , "RPC_S_PROCNUM_OUT_OF_RANGE" },
{ 1746 , "RPC_S_BINDING_HAS_NO_AUTH" },
{ 1747 , "RPC_S_UNKNOWN_AUTHN_SERVICE" },
{ 1748 , "RPC_S_UNKNOWN_AUTHN_LEVEL" },
{ 1749 , "RPC_S_INVALID_AUTH_IDENTITY" },
{ 1750 , "RPC_S_UNKNOWN_AUTHZ_SERVICE" },
{ 1751 , "EPT_S_INVALID_ENTRY" },
{ 1752 , "EPT_S_CANT_PERFORM_OP" },
{ 1753 , "EPT_S_NOT_REGISTERED" },
{ 1754 , "RPC_S_NOTHING_TO_EXPORT" },
{ 1755 , "RPC_S_INCOMPLETE_NAME" },
{ 1756 , "RPC_S_INVALID_VERS_OPTION" },
{ 1757 , "RPC_S_NO_MORE_MEMBERS" },
{ 1758 , "RPC_S_NOT_ALL_OBJS_UNEXPORTED" },
{ 1759 , "RPC_S_INTERFACE_NOT_FOUND" },
{ 1760 , "RPC_S_ENTRY_ALREADY_EXISTS" },
{ 1761 , "RPC_S_ENTRY_NOT_FOUND" },
{ 1762 , "RPC_S_NAME_SERVICE_UNAVAILABLE" },
{ 1763 , "RPC_S_INVALID_NAF_ID" },
{ 1764 , "RPC_S_CANNOT_SUPPORT" },
{ 1765 , "RPC_S_NO_CONTEXT_AVAILABLE" },
{ 1766 , "RPC_S_INTERNAL_ERROR" },
{ 1767 , "RPC_S_ZERO_DIVIDE" },
{ 1768 , "RPC_S_ADDRESS_ERROR" },
{ 1769 , "RPC_S_FP_DIV_ZERO" },
{ 1770 , "RPC_S_FP_UNDERFLOW" },
{ 1771 , "RPC_S_FP_OVERFLOW" },
{ 1772 , "RPC_X_NO_MORE_ENTRIES" },
{ 1773 , "RPC_X_SS_CHAR_TRANS_OPEN_FAIL" },
{ 1774 , "RPC_X_SS_CHAR_TRANS_SHORT_FILE" },
{ 1775 , "RPC_X_SS_IN_NULL_CONTEXT" },
{ 1777 , "RPC_X_SS_CONTEXT_DAMAGED" },
{ 1778 , "RPC_X_SS_HANDLES_MISMATCH" },
{ 1779 , "RPC_X_SS_CANNOT_GET_CALL_HANDLE" },
{ 1780 , "RPC_X_NULL_REF_POINTER" },
{ 1781 , "RPC_X_ENUM_VALUE_OUT_OF_RANGE" },
{ 1782 , "RPC_X_BYTE_COUNT_TOO_SMALL" },
{ 1783 , "RPC_X_BAD_STUB_DATA" },
{ 1784 , "ERROR_INVALID_USER_BUFFER" },
{ 1785 , "ERROR_UNRECOGNIZED_MEDIA" },
{ 1786 , "ERROR_NO_TRUST_LSA_SECRET" },
{ 1787 , "ERROR_NO_TRUST_SAM_ACCOUNT" },
{ 1788 , "ERROR_TRUSTED_DOMAIN_FAILURE" },
{ 1789 , "ERROR_TRUSTED_RELATIONSHIP_FAILURE" },
{ 1790 , "ERROR_TRUST_FAILURE" },
{ 1791 , "RPC_S_CALL_IN_PROGRESS" },
{ 1792 , "ERROR_NETLOGON_NOT_STARTED" },
{ 1793 , "ERROR_ACCOUNT_EXPIRED" },
{ 1794 , "ERROR_REDIRECTOR_HAS_OPEN_HANDLES" },
{ 1795 , "ERROR_PRINTER_DRIVER_ALREADY_INSTALLED" },
{ 1796 , "ERROR_UNKNOWN_PORT" },
{ 1797 , "ERROR_UNKNOWN_PRINTER_DRIVER" },
{ 1798 , "ERROR_UNKNOWN_PRINTPROCESSOR" },
{ 1799 , "ERROR_INVALID_SEPARATOR_FILE" },
{ 1800 , "ERROR_INVALID_PRIORITY" },
{ 1801 , "ERROR_INVALID_PRINTER_NAME" },
{ 1802 , "ERROR_PRINTER_ALREADY_EXISTS" },
{ 1803 , "ERROR_INVALID_PRINTER_COMMAND" },
{ 1804 , "ERROR_INVALID_DATATYPE" },
{ 1805 , "ERROR_INVALID_ENVIRONMENT" },
{ 1806 , "RPC_S_NO_MORE_BINDINGS" },
{ 1807 , "ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT" },
{ 1808 , "ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT" },
{ 1809 , "ERROR_NOLOGON_SERVER_TRUST_ACCOUNT" },
{ 1810 , "ERROR_DOMAIN_TRUST_INCONSISTENT" },
{ 1811 , "ERROR_SERVER_HAS_OPEN_HANDLES" },
{ 1812 , "ERROR_RESOURCE_DATA_NOT_FOUND" },
{ 1813 , "ERROR_RESOURCE_TYPE_NOT_FOUND" },
{ 1814 , "ERROR_RESOURCE_NAME_NOT_FOUND" },
{ 1815 , "ERROR_RESOURCE_LANG_NOT_FOUND" },
{ 1816 , "ERROR_NOT_ENOUGH_QUOTA" },
{ 1817 , "RPC_S_NO_INTERFACES" },
{ 1818 , "RPC_S_CALL_CANCELLED" },
{ 1819 , "RPC_S_BINDING_INCOMPLETE" },
{ 1820 , "RPC_S_COMM_FAILURE" },
{ 1821 , "RPC_S_UNSUPPORTED_AUTHN_LEVEL" },
{ 1822 , "RPC_S_NO_PRINC_NAME" },
{ 1823 , "RPC_S_NOT_RPC_ERROR" },
{ 1824 , "RPC_S_UUID_LOCAL_ONLY" },
{ 1825 , "RPC_S_SEC_PKG_ERROR" },
{ 1826 , "RPC_S_NOT_CANCELLED" },
{ 1827 , "RPC_X_INVALID_ES_ACTION" },
{ 1828 , "RPC_X_WRONG_ES_VERSION" },
{ 1829 , "RPC_X_WRONG_STUB_VERSION" },
{ 1898 , "RPC_S_GROUP_MEMBER_NOT_FOUND" },
{ 1899 , "EPT_S_CANT_CREATE" },
{ 1900 , "RPC_S_INVALID_OBJECT" },
{ 1901 , "ERROR_INVALID_TIME" },
{ 1902 , "ERROR_INVALID_FORM_NAME" },
{ 1903 , "ERROR_INVALID_FORM_SIZE" },
{ 1904 , "ERROR_ALREADY_WAITING" },
{ 1905 , "ERROR_PRINTER_DELETED" },
{ 1906 , "ERROR_INVALID_PRINTER_STATE" },
{ 1907 , "ERROR_PASSWORD_MUST_CHANGE" },
{ 1908 , "ERROR_DOMAIN_CONTROLLER_NOT_FOUND" },
{ 1909 , "ERROR_ACCOUNT_LOCKED_OUT" },
{ 6118 , "ERROR_NO_BROWSER_SERVERS_FOUND" },
{ 2000 , "ERROR_INVALID_PIXEL_FORMAT" },
{ 2001 , "ERROR_BAD_DRIVER" },
{ 2002 , "ERROR_INVALID_WINDOW_STYLE" },
{ 2003 , "ERROR_METAFILE_NOT_SUPPORTED" },
{ 2004 , "ERROR_TRANSFORM_NOT_SUPPORTED" },
{ 2005 , "ERROR_CLIPPING_NOT_SUPPORTED" },
{ 3000 , "ERROR_UNKNOWN_PRINT_MONITOR" },
{ 3001 , "ERROR_PRINTER_DRIVER_IN_USE" },
{ 3002 , "ERROR_SPOOL_FILE_NOT_FOUND" },
{ 3003 , "ERROR_SPL_NO_STARTDOC" },
{ 3004 , "ERROR_SPL_NO_ADDJOB" },
{ 3005 , "ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED" },
{ 3006 , "ERROR_PRINT_MONITOR_ALREADY_INSTALLED" },
{ 4000 , "ERROR_WINS_INTERNAL" },
{ 4001 , "ERROR_CAN_NOT_DEL_LOCAL_WINS" },
{ 4002 , "ERROR_STATIC_INIT" },
{ 4003 , "ERROR_INC_BACKUP" },
{ 4004 , "ERROR_FULL_BACKUP" },
{ 4005 , "ERROR_REC_NON_EXISTENT" },
{ 4006 , "ERROR_RPL_NOT_ALLOWED" },
{ 10004 , "WSAEINTR" },
{ 10009 , "WSAEBADF" },
{ 10013 , "WSAEACCES" },
{ 10014 , "WSAEFAULT" },
{ 10022 , "WSAEINVAL" },
{ 10024 , "WSAEMFILE" },
{ 10035 , "WSAEWOULDBLOCK" },
{ 10036 , "WSAEINPROGRESS" },
{ 10037 , "WSAEALREADY" },
{ 10038 , "WSAENOTSOCK" },
{ 10039 , "WSAEDESTADDRREQ" },
{ 10040 , "WSAEMSGSIZE" },
{ 10041 , "WSAEPROTOTYPE" },
{ 10042 , "WSAENOPROTOOPT" },
{ 10043 , "WSAEPROTONOSUPPORT" },
{ 10044 , "WSAESOCKTNOSUPPORT" },
{ 10045 , "WSAEOPNOTSUPP" },
{ 10046 , "WSAEPFNOSUPPORT" },
{ 10047 , "WSAEAFNOSUPPORT" },
{ 10048 , "WSAEADDRINUSE" },
{ 10049 , "WSAEADDRNOTAVAIL" },
{ 10050 , "WSAENETDOWN" },
{ 10051 , "WSAENETUNREACH" },
{ 10052 , "WSAENETRESET" },
{ 10053 , "WSAECONNABORTED" },
{ 10054 , "WSAECONNRESET" },
{ 10055 , "WSAENOBUFS" },
{ 10056 , "WSAEISCONN" },
{ 10057 , "WSAENOTCONN" },
{ 10058 , "WSAESHUTDOWN" },
{ 10059 , "WSAETOOMANYREFS" },
{ 10060 , "WSAETIMEDOUT" },
{ 10061 , "WSAECONNREFUSED" },
{ 10062 , "WSAELOOP" },
{ 10063 , "WSAENAMETOOLONG" },
{ 10064 , "WSAEHOSTDOWN" },
{ 10065 , "WSAEHOSTUNREACH" },
{ 10066 , "WSAENOTEMPTY" },
{ 10067 , "WSAEPROCLIM" },
{ 10068 , "WSAEUSERS" },
{ 10069 , "WSAEDQUOT" },
{ 10070 , "WSAESTALE" },
{ 10071 , "WSAEREMOTE" },
{ 10101 , "WSAEDISCON" },
{ 10091 , "WSASYSNOTREADY" },
{ 10092 , "WSAVERNOTSUPPORTED" },
{ 10093 , "WSANOTINITIALISED" },
{ 11001 , "WSAHOST_NOT_FOUND" },
{ 11002 , "WSATRY_AGAIN" },
{ 11003 , "WSANO_RECOVERY" },
{ 11004 , "WSANO_DATA" },
{ 0, 0 /*NULL*/}
};
