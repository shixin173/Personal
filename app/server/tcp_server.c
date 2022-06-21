#include "../../include/tcp_server.h"

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
        SaveLog("ERROR:Create socket fail\r\n");
        return -1;
    }

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(SERVER_PORT);
    ServerAddr.sin_addr.s_addr = inet_addr("0.0.0.0");
    if(0 > bind(sockfd, (struct sockaddr*)&ServerAddr),sizeof(ServerAddr))
    {
        SaveLog("ERROR:Bind failed\r\n");
        return -1;
    }
    if(0 < listen(sockfd,SERVER_MAX_CON))
    {
        SaveLog("ERROR:Listen failed\r\n");
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
            SaveLog("ERROR:accept failed\r\n");
        }
        if(0 == getsockname(connfd, &ClientAddr, (socklen_t *)&ulNameLen))
        {
            memcpy(&ClientAddrIn, &ClientAddr, ulNameLen);
            SaveLog("INFO:Client connect,IP:%s:%d",inet_ntoa(ClientAddrIn.sin_addr),ntohs(ClientAddrIn.sin_port));
        }
    }
}

VOID LogWright(CHAR *pcFile, CHAR *pcFunc, INT iLine, CONST CHAR *pcFormat, ...)
{
    va_list argList = {0};
    CHAR szLogTemp[MAX_LOG_SIZE] = {0};
    CHAR szLogHeader[256] = {0};
    FILE *fpLogFile;
    fpLogFile = fopen(LOG_FILE_PATH, "a+");
    if(NULL == fpLogFile)
    {
        printf("FILE:tcp_server.c LINE:%d fopen error!\r\n",__LINE__);
        return;
    }
    va_start(argList, pcFormat);
    printf("%s\r\n",pcFormat);
    vsnprintf(szLogTemp, MAX_LOG_SIZE, pcFormat, argList);
    va_end(argList);
    printf("%s\r\n",szLogTemp); 
    snprintf(szLogHeader, sizeof(szLogHeader), "FILE: %s  FUNC: %s  LINE: %d\r\n", pcFile, pcFunc, iLine);   
    fwrite(szLogHeader,strlen(szLogHeader),1,fpLogFile);
    fwrite(szLogTemp, strlen(szLogTemp), 1,fpLogFile);
}
