#ifndef _DATA_COMM_H
#define _DATA_COMM_H
#include <stdio.h>

typedef 	int  INT32;
typedef	short SHORT;
typedef 	long  LONG;
typedef     float  FLOAT;
typedef     double   DOUBLE;
typedef	char  CHAR;
typedef	unsigned char UCHAR;
typedef 	unsigned short  UINT16;
typedef 	unsigned int UINT32;
typedef     unsigned long ULONG;
typedef	unsigned long long UINT64;

enum  Major:uint16_t
{
    english=0,
    math,
    Electronic,
    art
};
enum class WorkType:uint16_t
{
    teacher=0,
    police,
    WhiteCollar,
    farmers
};

typedef struct
{
    uint16_t Grade;
    Major major;
    uint16_t Room;
} Student;//
#pragma pack (1)
typedef struct
{
    uint16_t workingyears;
    WorkType workType;
    uint16_t Years;
    uint16_t Sex;
} Workers;//
#pragma pack (1)

#endif



#endif // _DATA_COMM_H
