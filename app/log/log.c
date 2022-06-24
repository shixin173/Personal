#include "log.h"

VOID LogWright(CHAR *pcModule, CHAR *pcFile, CHAR *pcFunc, INT iLine, CONST CHAR *pcFormat, ...)
{
    va_list argList = {0};
    CHAR szLogTemp[MAX_LOG_SIZE] = {0};
    CHAR szLogHeader[256] = {0};
    CHAR szFileName[64] = {0};
    FILE *fpLogFile;
    CHAR szTime[64] = {0};
    INT iRes = 0;
    struct tm *stNowTime;
    time_t nowTime;

    time(&nowTime);
    stNowTime = localtime(&nowTime);
    sprintf(szFileName, "../log/%04d%02d%02d%s.log", stNowTime->tm_year + 1900, stNowTime->tm_mon + 1, stNowTime->tm_mday, pcModule);
    sprintf(szTime, "%d-%d-%d %d:%d:%d", stNowTime->tm_year + 1900, stNowTime->tm_mon + 1, stNowTime->tm_mday, stNowTime->tm_hour, stNowTime->tm_min, stNowTime->tm_sec);
    va_start(argList, pcFormat);    
    vsnprintf(szLogTemp, MAX_LOG_SIZE, pcFormat, argList);
    va_end(argList);
    snprintf(szLogHeader, sizeof(szLogHeader), "[%s]  [FILE: %s]  [FUNC: %s]  [LINE: %d] ------ ", szTime, pcFile, pcFunc, iLine);
    fpLogFile = fopen(szFileName, "a+");
    if(NULL == fpLogFile)
    {
        printf("FILE:tcp_client_log.c LINE:%d fopen %s error!\r\n", __LINE__, szFileName);
        return;
    }
    fwrite(szLogHeader, 1, strlen(szLogHeader), fpLogFile);
    fwrite(szLogTemp, 1, strlen(szLogTemp), fpLogFile);
    fwrite("\r\n", 1, 2, fpLogFile);
    fclose(fpLogFile);
}
