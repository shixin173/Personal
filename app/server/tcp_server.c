#include "../../include/tcp_server.h"

VOID main()
{
    SaveLog("Create socket fail\r\n");
}

UINT Socket_Init(VOID)
{
    UINT sockfd = 0;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        SaveLog("Create socket fail\r\n");
    }
}

VOID LogWright(CHAR *pcFile, CHAR *pcFunc, CONST CHAR *pcFormat, ...)
{
    va_list argList = {0};
    CHAR szLogTemp[MAX_LOG_SIZE];
    FILE *fpLogFile;
    fpLogFile = fopen(LOG_FILE_PATH, "a+");
    if(NULL == fpLogFile)
    {
        printf("FILE:tcp_server.c LINE:%d fopen error!\r\n",__LINE__);
        return;
    }
    va_start(argList, pcFormat);
    vsnprintf(szLogTemp, MAX_LOG_SIZE, pcFormat, argList);
    va_end(argList);
    fwrite(szLogTemp, MAX_LOG_SIZE, 1,fpLogFile);
}