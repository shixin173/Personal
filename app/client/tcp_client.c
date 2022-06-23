#include "../../include/log.h"
#include "../../include/tcp_client.h"

VOID main()
{
    INT sockfd = 0;

    sockfd = ConnectServer();
}

INT ConnectServer()
{
    INT sockfd = 0;
    struct sockaddr_in cli_addr;

    memset(&cli_addr, 0, sizeof(cli_addr));
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_port   = htons(SERVER_PORT);
    cli_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        SaveLog(MODULE_TCPCLIENT, "ERROR:Create socket fail\r\n");
    }
    if(0 > connect(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr)))
    {
        SaveLog(MODULE_TCPCLIENT, "ERROR:connect server failed\r\n");
    }
    SaveLog(MODULE_TCPCLIENT, "INFO:connect server success\r\n");
    return sockfd;
}
