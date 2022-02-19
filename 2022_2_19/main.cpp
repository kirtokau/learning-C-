#include "mainwindow.h"
#include <QApplication>
#include "connection_user.h"
#include <QTextCodec>
#include "connection_device.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    if(!createConnection())
       return 1;
    MainWindow w;
    w.show();

    return a.exec();
}
