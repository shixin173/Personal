
#include "tcp_client.h"
#include "tcp_client_log.h"

VOID main()
{
    INT sockfd = 0;
    INT iRes   = 0;
    CHAR szBuf[1024] = {"hello"};

    sockfd = ConnectServer();

    iRes = send(sockfd, szBuf, sizeof(szBuf), 0);
    if(0 > iRes)
    {
        SaveLog("ERROR:Send buf failed,iRes:%d\r\n", iRes);
        return;
    }
    SaveLog("INFO:Send buf:%s\r\nLen:%d\r\n", szBuf, iRes);
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
        SaveLog("ERROR:Create socket fail\r\n");
    }
    if(0 > connect(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr)))
    {
        SaveLog("ERROR:connect server failed\r\n");
    }
    SaveLog("INFO:connect server success\r\n");
    return sockfd;
}

