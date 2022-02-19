#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QSqlTableModel>
class mainwindow2 : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainwindow2(QWidget *parent = nullptr);

signals:
private:
QSqlTableModel *model;
};

#endif // MAINWINDOW2_H
