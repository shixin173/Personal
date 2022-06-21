#include "../../include/tcp_server.h"

VOID main()
{
    int a = 1;
    SaveLog("Create socket fail,%d\r\n",a);
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

VOID LogWright(CHAR *pcFile, CHAR *pcFunc, CHAR *pcLine, CONST CHAR *pcFormat, ...)
{
    va_list argList = {0};
    CHAR *pcLogTemp = NULL;
    FILE *fpLogFile;
    fpLogFile = fopen(LOG_FILE_PATH, "a+");
    if(NULL == fpLogFile)
    {
        printf("FILE:tcp_server.c LINE:%d fopen error!\r\n",__LINE__);
        return;
    }
    pcLogTemp = malloc(MAX_LOG_SIZE);
    if(NULL == pcLogTemp)
    {
    	printf("malloc file\r\n");
	return;
    }
    va_start(argList, pcFormat);
    printf("%s\r\n",pcFormat);
    vsnprintf(pcLogTemp, MAX_LOG_SIZE, pcFormat, argList);
    va_end(argList);
    printf("%s\r\n",pcLogTemp);
    snprintf(pcLogTemp, sizeof(pcFile) + sizeof(pcFunc) + sizeof(pcLine), "FILE:%s   FUNC:%s  LINE:%s\r\n", pcFile, pcFunc, pcLine);
    printf("%s\r\n",pcLogTemp);
    fwrite(pcLogTemp, strlen(pcLogTemp), 1,fpLogFile);
}
