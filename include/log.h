#ifndef _LOG_H_
#define _LOG_H_

#include "common.h"

#define MODULE_TCPSERVER    "tcp_server"
#define MODULE_TCPCLIENT    "tcp_client"

#define MAX_LOG_SIZE    4096

#define SaveLog(module, format, ...)\
{\
    LogWright((CHAR *)module, (CHAR *)__FILE__, (CHAR *)__FUNCTION__, (INT)__LINE__, format, ##__VA_ARGS__);\
}

VOID LogWright(CHAR *pcModule, CHAR *pcFile, CHAR *pcFunc, INT iLine, CONST CHAR *pcFormat, ...);

#endif
