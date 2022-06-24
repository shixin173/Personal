#ifndef _TCP_CLIENT_H_
#define _TCP_CLIENT_H_

#include "../../common/common.h"

#define SERVER_PORT     14000
#define SERVER_IP       "116.205.242.50"

INT ConnectServer();
VOID Client_Process(INT sockfd);

#endif


