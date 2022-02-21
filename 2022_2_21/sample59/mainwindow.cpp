#include "mainwindow.h"
#include "ui_mainwindow.h"
#define DATA_LEN 64

#pragma pack(1)
//接收数据的格式
typedef struct receiveData
{
    uchar header[2];            //帧头
    uchar dataLength;          //数据个数（1字节），小于64
    char my_data[DATA_LEN];    //数据（小于64字节）
    uchar check_sum;           //校验和（1字节） 前面所有字节累加和
}st_receivedata;
#pragma pack()

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    setWindowTitle("服务器");
    m_s=new QTcpServer(this);
    m_s->listen(QHostAddress::AnyIPv4,8888);
    connect(m_s,&QTcpServer::newConnection,this,[=](){
    m_tcp=m_s->nextPendingConnection();
     //检查是否可以接收数据
    connect(m_tcp,&QTcpSocket::readyRead,this,[=]()
    {     receiveData st_receiveTcpData, *get_Data;
        QByteArray buffer;
        QString str;
        //读取缓冲区数据
        buffer = m_tcp->readAll();
        if(!buffer.isEmpty())
        {
            memset(&st_receiveTcpData,0,sizeof (st_receiveTcpData));

            get_Data = (receiveData*)buffer.data();        //强转为结构体，需要用结构体指针接收

            //读取帧头
            for(int i = 0; i < sizeof (st_receiveTcpData.header); i++)
            {
                st_receiveTcpData.header[i] = get_Data->header[i];
            }
            //读取数据长度
            st_receiveTcpData.dataLength = get_Data->dataLength;
            //读取数据
            for(int i = 0; i < buffer.length() - 4; i++)//buffer的长度减去header、datalength、check_sum的长度就是数据的长度
            {
                st_receiveTcpData.my_data[i] = get_Data->my_data[i];
            }
            //读取校验和，因为发送的时候避免my_data有空内容，所以把校验和放在了my_data后面，所以此处只
            //需要读取my_data后面的值就是校验和了。
            get_Data->check_sum = get_Data->my_data[buffer.length()-4];
            st_receiveTcpData.check_sum = get_Data->check_sum;

            //将my_data数据转为QString
            str = QString(QLatin1String(st_receiveTcpData.my_data));
            //将my_data在文本框显示
            ui->record->insertPlainText("receive："+str+"\n");

            //释放内存
            free(get_Data);
            buffer.clear();
            buffer.squeeze();
        }


        //QByteArray data=m_tcp->readAll();
        //ui->record->append("客服端say:"+data);
     });
}
);}
MainWindow::~MainWindow()
{
    delete ui;
}


