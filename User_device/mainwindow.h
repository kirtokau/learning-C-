#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QtNetwork>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static bool connectDB();

private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_3_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QUdpSocket *sender;
};
#endif // MAINWINDOW_H
