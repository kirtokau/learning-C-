#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QHostAddress>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&tcpSocket,SIGNAL(readyRead()),this,SLOT(onReadReady()));
    connect(&tcpSocket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(&tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));
    tcpSocket.connectToHost("127.0.0.1",8888);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onReadready()
{
    QObject *obj=this->sender();
    QTcpSocket *socket= qobject_cast<QTcpSocket*>(obj);
    QByteArray data=socket->readAll();
    ui->textEdit->append(data);

}

void MainWindow::onConnected()
{
    qDebug()<<"connected";

}
void MainWindow::onDisconnected()
{
    qDebug()<<"disconnected";
}
void MainWindow::onError(QAbstractSocket::SocketError socketError)
{
    qDebug()<<"error:"<<socketError;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
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
