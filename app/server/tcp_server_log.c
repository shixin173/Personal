#include "tcp_server_log.c"

VOID LogWright(CHAR *pcModule, CHAR *pcFile, CHAR *pcFunc, INT iLine, CONST CHAR *pcFormat, ...)
{
    va_list argList = {0};
    CHAR szLogTemp[MAX_LOG_SIZE] = {0};
    CHAR szLogHeader[256] = {0};
    CHAR szLogFilePath[64] = {0};  
    FILE *fpLogFile;
    
    va_start(argList, pcFormat);    
    vsnprintf(szLogTemp, MAX_LOG_SIZE, pcFormat, argList);
    va_end(argList);
    snprintf(szLogHeader, sizeof(szLogHeader), "FILE: %s  FUNC: %s  LINE: %d\r\n", pcFile, pcFunc, iLine);
    fpLogFile = fopen(LOG_FILE_PATH, "a+");
    if(NULL == fpLogFile)
    {
        printf("FILE:log.c LINE:%d fopen %s error!\r\n", __LINE__, szLogFilePath);
        return;
    } 
    fwrite(szLogHeader,strlen(szLogHeader), 1,fpLogFile);
    fwrite(szLogTemp, strlen(szLogTemp), 1,fpLogFile);
}
