#ifndef _TCP_SERVER_H_
#define _TCP_SERVER_H_

#include "../../common/common.h"

#define SERVER_PORT     14000
#define SERVER_MAX_CON  100
#define SERVER_IP       "116.205.242.50"
#define MAX_LOG_SIZE    4096

INT  Socket_Init();
VOID Socket_Process(INT sockfd);
VOID Server_Process(VOID *void_sockfd);

#endif


