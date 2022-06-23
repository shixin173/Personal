#include "tcp_server_log.h"

VOID LogWright(CHAR *pcFile, CHAR *pcFunc, INT iLine, CONST CHAR *pcFormat, ...)
{
    va_list argList = {0};
    CHAR szLogTemp[MAX_LOG_SIZE] = {0};
    CHAR szLogHeader[256] = {0};
    FILE *fpLogFile;
    INT iRes = 0;
    
    printf("1.------------%d\r\n", __LINE__);
    va_start(argList, pcFormat);    
    vsnprintf(szLogTemp, MAX_LOG_SIZE, pcFormat, argList);
    va_end(argList);
    snprintf(szLogHeader, sizeof(szLogHeader), "[FILE: %s]  [FUNC: %s]  [LINE: %d] ------ ", pcFile, pcFunc, iLine);
    printf("2.------------%d\r\n", __LINE__);
    fpLogFile = fopen(LOG_FILE_PATH, "a+");
    if(NULL == fpLogFile)
    {
        printf("FILE:tcp_server_log.c LINE:%d fopen %s error!\r\n", __LINE__, LOG_FILE_PATH);
        return;
    } 
    printf("3.------------%d\r\n", __LINE__);
    iRes = fwrite(szLogHeader, 1, strlen(szLogHeader), fpLogFile);
    printf("4.------------%d--iRes:%d\r\n", __LINE__,iRes);
    iRes = fwrite(szLogTemp, 1, strlen(szLogTemp), fpLogFile);
    printf("5.------------%d--iRes:%d\r\n", __LINE__,iRes);
    fclose(fpLogFile);
}
