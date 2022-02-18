#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
void onConnected();
void onDisconnected();
void onError(QAbstractSocket::SocketError socketError);
void onReadready();
private slots:
void on_pushButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QTcpSocket tcpSocket;
};
#endif // MAINWINDOW_H
