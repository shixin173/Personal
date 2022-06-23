#include "../../include/tcp_server.h"
#include "../../include/log.h"

VOID main()
{
    INT sockfd = 0;

    sockfd = Socket_Init();
    if(0 > sockfd)
    {
        printf("exec failed\r\n");
        return;
    }
    Socket_Process(sockfd);
}

INT Socket_Init()
{
    INT sockfd = 0;    
    struct sockaddr_in ServerAddr = {0};
    
    memset(&ServerAddr, 0, sizeof(ServerAddr));
    

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(0 > sockfd)
    {
        SaveLog(MODULE_TCPSERVER, "ERROR:Create socket fail\r\n");
        return -1;
    }

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(SERVER_PORT);
    ServerAddr.sin_addr.s_addr = inet_addr("0.0.0.0");
    if(0 > bind(sockfd, (struct sockaddr*)&ServerAddr,sizeof(ServerAddr)))
    {
        SaveLog(MODULE_TCPSERVER, "ERROR:Bind failed\r\n");
        return -1;
    }
    if(0 < listen(sockfd,SERVER_MAX_CON))
    {
        SaveLog(MODULE_TCPSERVER, "ERROR:Listen failed\r\n");
        return -1;
    }
    return sockfd;
}

VOID Socket_Process(INT sockfd)
{
    INT connfd = 0;
    ULONG ulNameLen = 0;
    struct sockaddr ClientAddr = {0};
    struct sockaddr_in ClientAddrIn = {0};

    memset(&ClientAddr, 0, sizeof(ClientAddr));
    memset(&ClientAddrIn, 0, sizeof(ClientAddrIn));
    ulNameLen = sizeof(struct sockaddr);

    while(1)
    {
        connfd = accept(sockfd, NULL, NULL);
        if(0 > connfd)
        {
            SaveLog(MODULE_TCPSERVER, "ERROR:accept failed\r\n");
        }
        if(0 == getsockname(connfd, &ClientAddr, (socklen_t *)&ulNameLen))
        {
            memcpy(&ClientAddrIn, &ClientAddr, ulNameLen);
            SaveLog(MODULE_TCPSERVER, "INFO:Client connect,IP:%s:%d",inet_ntoa(ClientAddrIn.sin_addr),ntohs(ClientAddrIn.sin_port));
        }
    }
}



