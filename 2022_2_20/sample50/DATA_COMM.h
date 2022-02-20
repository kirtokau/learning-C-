#ifndef DATA_COMM_H
#define DATA_COMM_H
#include <stdio.h>
#pragma pack(1)     //设置结构体为1字节对齐
typedef struct sendData
{
    uchar header[2];          //帧头（2字节） uchar才能存十六进制数
    uchar dataLength;        //数据个数（1字节），小于64
    char my_data[DATA_COMM];  //数据（小于64字节）
    uchar check_sum;         //校验和（1字节） 前面所有字节累加和
}senddata;
#pragma pack()		//结束结构体对齐设置


#endif // DATA_COMM_H
