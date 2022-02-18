#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHostAddress>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bool ok=server.listen(QHostAddress::AnyIPv4,8888);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewConnection()
{
    //使用这个Socket客服端进行通信
    QTcpSocket *socket=server.nextPendingConnection();
    //连接信号和槽
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadReady()));
    connect(socket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));
}
void MainWindow::onConnected()// 连接成功
{
    qDebug()<<"connected";
}
void MainWindow::onDisconnected()
{
    qDebug()<<"disconnected";
}
void MainWindow::onError(QAbstractSocket::SocketError socketError)// 出错
{

    qDebug()<<"error:"<<socketError;
}

void MainWindow::onReadready()
{
    QObject *obj =this->sender();
    QTcpSocket *socket=qobject_cast<QTcpSocket*>(obj);
    QByteArray data = socket->readAll();
    ui->textEdit->append(data);

    qDebug()<<data;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    //发送消息

        QString data = ui->textEdit->toPlainText();
        if(data.length() != 0)
        {
           tcpSocket.write(data.toLatin1());
            ui->textEdit->clear();
            ui->textEdit->append("发送文本消息成功！");
            data.clear();
        }
        else
        {
            ui->textEdit->append("不能发送空的消息！");
        }



}
