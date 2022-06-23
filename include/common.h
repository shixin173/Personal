#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <pthread.h>

#define ERROR_SUCCESS    0UL
#define ERROR_FAILED     1UL
#define ERROR_NOTSUPPORT 2UL

#define INT         int
#define CHAR        char
#define FLOAT       float
#define DOUBLE      double
#define SHORT       short
#define LONG        long
#define UINT        unsigned int
#define ULONG       unsigned long
#define UCHAR       unsigned char
#define USHORT      unsigned short
#define VOID        void
#define STATIC      static
#define CONST       const

#endif
