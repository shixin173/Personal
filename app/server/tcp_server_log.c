#include "tcp_server_log.h"

VOID LogWright(CHAR *pcFile, CHAR *pcFunc, INT iLine, CONST CHAR *pcFormat, ...)
{
    va_list argList = {0};
    CHAR szLogTemp[MAX_LOG_SIZE] = {0};
    CHAR szLogHeader[256] = {0};
    FILE *fpLogFile;
    CHAR szTime[64] = {0};
    INT iRes = 0;

    iRes = Exec_Shell("date", szTime, sizeof(szTime));
    va_start(argList, pcFormat);    
    vsnprintf(szLogTemp, MAX_LOG_SIZE, pcFormat, argList);
    va_end(argList);
    snprintf(szLogHeader, sizeof(szLogHeader), "%s[FILE: %s]  [FUNC: %s]  [LINE: %d] ------ ", szTime, pcFile, pcFunc, iLine);
    fpLogFile = fopen(LOG_FILE_PATH, "a+");
    if(NULL == fpLogFile)
    {
        printf("FILE:tcp_server_log.c LINE:%d fopen %s error!\r\n", __LINE__, LOG_FILE_PATH);
        return;
    }
    fwrite(szLogHeader, 1, strlen(szLogHeader), fpLogFile);
    fwrite(szLogTemp, 1, strlen(szLogTemp), fpLogFile);
    fclose(fpLogFile);
}
