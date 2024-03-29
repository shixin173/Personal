#include "tcp_client.h"
#include "../log/log.h"
#include "../../include/tcp.h"

VOID main()
{
    INT sockfd = 0;
    

    sockfd = ConnectServer();
    Client_Process(sockfd);   
}

VOID Client_Process(INT sockfd)
{
    INT i = 0;
    INT iRes   = 0;
    CHAR szBuf[1024] = {0};

    while(i++ < 10)
    {
        sprintf(szBuf, "Client send msg,times:%d\r\n", i);
        iRes = send(sockfd, szBuf, sizeof(szBuf), 0);    
        if(0 > iRes)
        {
            SaveLog(MODULE_TCPCLIENT, "ERROR:Send buf failed,iRes:%d\r\n", iRes);
            return;
        }
        SaveLog(MODULE_TCPCLIENT, "INFO:Send buf:%s\r\nLen:%d\r\n", szBuf, iRes);
        sleep(1);
    }
    while(1);
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


