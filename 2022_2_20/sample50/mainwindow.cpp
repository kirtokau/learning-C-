#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHostAddress>
#include <QString>
#include <iostream>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include<QVector>
#include <QMessageBox>
#include <QSqlError>
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



    QString msg=ui->msg->toPlainText();
    m_tcp->write(msg.toUtf8());
    ui->record->append("客户端say:"+msg);

}
