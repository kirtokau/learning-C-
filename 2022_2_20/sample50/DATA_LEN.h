#ifndef DATA_LEN_H
#define DATA_LEN_H
#pragma pack(1)     //设置结构体为1字节对齐
typedef struct sendData
{
    uchar header;          //帧头（2字节） uchar才能存十六进制数
    uchar CMD;
    uchar dataLength;        //数据个数（1字节），小于64
    uchar Type;              //发送类型
    char my_data[DATA_LEN];  //数据（小于64字节）
}senddata;
#pragma pack()		//结束结构体对齐设置

#endif // DATA_LEN_H
