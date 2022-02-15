#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlDatabase"
#include "QMessageBox"
#include "QSqlError"
#include "QDebug"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sender = new QUdpSocket(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::connectDB()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("admin");
    db.setDatabaseName("sample_1");
    if(!db.open())
    {
        //MainWindow::on_pushButton_clicked();
       // QMessageBox::warning(this,"wrong",db.lastError().text());
        return false;
    }
    else
    {
        return true;
    }
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    static QSqlQueryModel *mode= new QSqlQueryModel(ui->tableView);

     mode->setQuery("select * from User");
     mode->setHeaderData(0,Qt::Horizontal,tr("Username"));
     mode->setHeaderData(1, Qt::Horizontal, tr("Sex"));
     ui->tableView->setModel(mode);
}

void MainWindow::on_pushButton_2_clicked(bool checked)
{
    static QSqlQueryModel *mode= new QSqlQueryModel(ui->tableView);

     mode->setQuery("select * from device");
     mode->setHeaderData(0,Qt::Horizontal,tr("Account"));
     mode->setHeaderData(1, Qt::Horizontal, tr("Name"));
     ui->tableView->setModel(mode);
}

void MainWindow::on_pushButton_3_clicked(bool checked)
{
    QByteArray datagram = "hello world!";
        sender->writeDatagram(datagram.data(),datagram.size(),
                              QHostAddress::Broadcast,45454);
}
