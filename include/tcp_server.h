#ifndef _TCP_SERVER_H_
#define _TCP_SERVER_H_

#include "common.h"

#define SERVER_PORT     14000
#define SERVER_MAX_CON  100
#define SERVER_IP       "116.205.242.50"
#define MAX_LOG_SIZE    4096
#define LOG_FILE_PATH   "../log/tcp_server.log"

#define SaveLog(format, ...)\
{\
    LogWright((CHAR *)__FILE__, (CHAR *)__FUNCTION__, (INT)__LINE__, format, ##__VA_ARGS__);\
}

UINT Socket_Init(VOID);
VOID LogWright(CHAR *pcFile, CHAR *pcFunc, INT iLine , CONST CHAR *pcFormat, ...);

#endif
