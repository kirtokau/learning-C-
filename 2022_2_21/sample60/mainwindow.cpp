#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHostAddress>
#include<cstring>
#include<QString>
#include <QMessageBox>
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("客户端");
     m_tcp=new QTcpSocket(this);
     m_tcp->connectToHost("127.0.0.1",8888);
     connect(m_tcp,&QTcpSocket::readyRead,this,[=]()
     {
         QByteArray data=m_tcp->readAll();
         ui->record->append("服务器say:"+data);
      });
     connect(m_tcp,&QTcpSocket::disconnected,this,[=]()
     {
         m_tcp->close();
         m_tcp->deleteLater();
         ui->record->append("服务器和客户端已经断开了连接...");

     });
     connect(m_tcp,&QTcpSocket::connected,this,[=](){
       ui->record->append("已经连接到了服务器...");

     });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked(bool checked)
{
    char data[64];
    QString str="12fff";
    QByteArray ba=str.toLatin1();
    char *temp=ba.data();
    memcpy(data,temp,ba.length());
    sendData st_senddata;
    QByteArray get_data, sendTcpData;

    //senddata.header.resize(2);
    st_senddata.header[0] = 0x55;		//假设帧头就是0X55 0XAA
    st_senddata.header[1] = 0xAA;

    str = ui->msg->toPlainText().toLocal8Bit();
    //数据超长提醒
    if(str.length() > 64)
    {
         QMessageBox::information(this,tr("提示"),tr("数据长度限制为64！"),QMessageBox::Yes);
          ui->msg->clear();
         return;
    }
    //填好数据
    get_data=(QByteArray)ui->msg->toPlainText().toLocal8Bit(); //直接获取用户输入的同时将QString转成QByteArray
    temp=get_data.data();     //将QByteArray转成char*
    memcpy(st_senddata.my_data,temp,get_data.length());     //不拷贝内存传结构体时就只会传一个指针过去

    //填好数据长度
    st_senddata.dataLength = get_data.length();

    //填好校验和，就是my_data长度+header两字节+datalength一字节
    st_senddata.check_sum = get_data.length() + 3;

    //使用字节数组,将结构体转为字符数组，发送的是字符数组（数据在传输过程中都是byte类型的）
    //直接sizeof（senddata）内存会变小，设置了对齐方式解决,,,只给他赋予数据长度加帧头、校验和所占字节
    sendTcpData.resize((get_data.length()+3));

    //将封装好的结构体转为QByteArray数组，因为传输都是Byte类型
    memcpy(sendTcpData.data(),&st_senddata,(get_data.length()+3));
    /*因为数据长度可能没有占满64字节，校验和又是存在数据之后的，所以有一段内存可能是空的，因此此处手动
    把校验和值添加在QByteArray数组最后，这样发送出去的数据就是连续的*/
    sendTcpData.append(st_senddata.check_sum);
    //发送完整的QByteArray数组，包含所有结构体信息
    m_tcp->write(sendTcpData);
    ui->msg->insertPlainText("send："+str+"\n");

    m_tcp->flush();                    //释放socket缓存
    ui->msg->clear();         //发送出去后将发送文本清空
    //释放指针、清空QByteArray数组
    free(temp);
    temp = NULL;
    get_data.clear();
    get_data.squeeze();
    sendTcpData.clear();
    sendTcpData.squeeze();

    //QString msg=ui->msg->toPlainText();
    //m_tcp->write(msg.toUtf8());
    //ui->record->append("客户端say:"+msg);
}
