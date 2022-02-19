#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database2.db");
    if(!db.open()) return false;
    QSqlQuery query;
    query.exec(QString(
    "create table device (id int primary key, name vchar)"));
    query.exec(QString("insert into device values (0,'刘明')"));
    query.exec(QString("insert into device values (1,'陈刚')"));
    query.exec(QString("insert into device values (2,'王红')"));
    return true;
}
#endif // CONNECTION_H
