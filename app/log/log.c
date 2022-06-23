#include "../../include/log.h"

VOID LogWright(CHAR *pcModule, CHAR *pcFile, CHAR *pcFunc, INT iLine, CONST CHAR *pcFormat, ...)
{
    va_list argList = {0};
    CHAR szLogTemp[MAX_LOG_SIZE] = {0};
    CHAR szLogHeader[256] = {0};
    CHAR szLogFilePath[64] = {0};  
    FILE *fpLogFile;
    
    va_start(argList, pcFormat);
    printf("%s\r\n",pcFormat);
    vsnprintf(szLogTemp, MAX_LOG_SIZE, pcFormat, argList);
    va_end(argList);
    printf("%s\r\n",szLogTemp); 
    snprintf(szLogHeader, sizeof(szLogHeader), "FILE: %s  FUNC: %s  LINE: %d\r\n", pcFile, pcFunc, iLine);    
    if(0 == strcmp(pcModule,"tcp_server"))
    {
        memcpy(szLogFilePath, sizeof(szLogFilePath), "../../log/tcp_server.log");
    }    
    else
    {
        memcpy(szLogFilePath, sizeof(szLogFilePath), "../../log/log.log");
    }    
    
    fpLogFile = fopen(szLogFilePath, "a+");
    if(NULL == fpLogFile)
    {
        printf("FILE:log.c LINE:%d fopen error!\r\n",__LINE__);
        return;
    }
    
    fwrite(szLogHeader,strlen(szLogHeader), 1,fpLogFile);
    fwrite(szLogTemp, strlen(szLogTemp), 1,fpLogFile);
}
