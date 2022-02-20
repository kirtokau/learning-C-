#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("服务器");
    m_s=new QTcpServer(this);
    m_s->listen(QHostAddress::AnyIPv4,8888);
    connect(m_s,&QTcpServer::newConnection,this,[=](){
    m_tcp=m_s->nextPendingConnection();
     //检查是否可以接收数据
    connect(m_tcp,&QTcpSocket::readyRead,this,[=]()
    {

        QByteArray data=m_tcp->readAll();
        ui->record->append("客服端say:"+data);
     });
    //connect(m_tcp,&QTcpSocket::disconnected,this,[=](){
      //m_tcp->close();
        //m_tcp->deleteLater();

   // });
    //});

}
);
}

MainWindow::~MainWindow()
{
    delete ui;
}



