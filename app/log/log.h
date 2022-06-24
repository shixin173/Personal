#ifndef _LOG_H_
#define _LOG_H_

#include "../../common/common.h"

#define MAX_LOG_SIZE    4096

#define MODULE_TCPSERVER    "tcp_server"
#define MODULE_TCPCLIENT    "tcp_client"

#define SaveLog(module, format, ...)\
{\
    LogWright((CHAR *)module, (CHAR *)__FILE__, (CHAR *)__FUNCTION__, (INT)__LINE__, format, ##__VA_ARGS__);\
}

extern VOID LogWright(CHAR *pcModule, CHAR *pcFile, CHAR *pcFunc, INT iLine, CONST CHAR *pcFormat, ...);

#endif
