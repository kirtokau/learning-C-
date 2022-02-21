#include "data_len.h"
#include <QString>
#include<cstring>
#include <QMessageBox>
DATA_LEN::DATA_LEN()
{
#define DATA_LEN 64
#pragma pack(1)     //设置结构体为1字节对齐
typedef struct sendData
{
    char header[2];          //帧头（2字节） uchar才能存十六进制数
    char dataLength;        //数据个数（1字节），小于64
    char my_data[DATA_LEN];  //数据（小于64字节）
    char check_sum;         //校验和（1字节） 前面所有字节累加和
}senddata;
#pragma pack()		//结束结构体对齐设置
char data[64];
QString str="12fff";
QByteArray ba=str.toLatin1();
char *temp=ba.data();
memcpy(data,temp,ba.length());


}
