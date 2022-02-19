#include "mainwindow2.h"

mainwindow2::mainwindow2(QWidget *parent) : QMainWindow(parent)
{


        model = new QSqlTableModel(this);
        model->setTable("device");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select(); //选取整个表的所有行
        //不显示name属性列,如果这时添加记录，则该属性的值添加不上
        // model->removeColumn(1);
        ui->tableView->setModel(model);
        //使其不可编辑
        //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


}
