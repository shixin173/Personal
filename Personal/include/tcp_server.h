#ifndef _TCP_SERVER_H_
#define _TCP_SERVER_H_

#include "common.h"

#define SERVER_PORT     14000
#define SERVER_MAX_CON  100
#define SERVER_IP       "116.205.242.50"
#define MAX_LOG_SIZE    4096
#define LOG_FILE_PATH   "../../log/tcp_server.log"

#define SaveLog(module, format, ...)\
{\
    LogWright(moudle,(CHAR *)__FILE__, (CHAR *)__FUNCTION__, format, ##__VA_ARGS__);\
}