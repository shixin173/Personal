#include "common.h"

INT Exec_Shell(CONST CHAR* pcCmd, CHAR *pcOutBuf, INT iLen)
{
    FILE *pFile = NULL;
    
    pFile = popen(pcCmd, "r");
    if(NULL == pFile)
    {
        return -1;
    }
    fread(pcOutBuf, 1, iLen, pFile);
    pclose(pFile);
    return 0;
}
