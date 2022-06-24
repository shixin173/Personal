#ifndef _TCP_H_
#define _TCP_H_
#include "../common/common.h"

#define TCP_MSG_HEAD_LEN sizeof(TCP_MSG_HEAD_S)

typedef struct tagTcpMsgHead
{
    UINT uiMsgType;
    UINT uiMsgLen;
}TCP_MSG_HEAD_S;

typedef enum
{
    MSG_NORMAL = 0xFF00, //0xFF00
    MSG_ERROR            //0xFF01
}TCP_MSG_TYPE_E;

extern TCP_MSG_HEAD_S g_stTcpMsgHead;

#endif
