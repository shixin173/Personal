#ifndef _TCP_SERVER_LOG_H
#define _TCP_SERVER_LOG_H

#include "common.h"

#define LOG_FILE_PATH    "../log/tcp_server.log"

#define MAX_LOG_SIZE    4096

#define SaveLog(module, format, ...)\
{\
    LogWright((CHAR *)module, (CHAR *)__FILE__, (CHAR *)__FUNCTION__, (INT)__LINE__, format, ##__VA_ARGS__);\
}

VOID LogWright(CHAR *pcModule, CHAR *pcFile, CHAR *pcFunc, INT iLine, CONST CHAR *pcFormat, ...);

#endif
