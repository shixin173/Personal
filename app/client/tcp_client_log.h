#ifndef _TCP_SERVER_LOG_H
#define _TCP_SERVER_LOG_H

#include "../../include/common.h"

#define LOG_FILE_PATH    "../log/tcp_client.log"

#define MAX_LOG_SIZE    4096

#define SaveLog(format, ...)\
{\
    LogWright((CHAR *)__FILE__, (CHAR *)__FUNCTION__, (INT)__LINE__, format, ##__VA_ARGS__);\
}

VOID LogWright(CHAR *pcFile, CHAR *pcFunc, INT iLine, CONST CHAR *pcFormat, ...);

#endif
