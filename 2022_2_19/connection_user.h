#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    if(!db.open()) return false;
    QSqlQuery query;
    query.exec(QString(
    "create table User2 (id int primary key, name vchar,  sex vchar ,account vchar , password  vchar,signuptime vchar )"));
    query.exec(QString("insert into User2 values (0,'李勇','男','2022235','6695','2016-05-06')"));
    query.exec(QString("insert into User2 values (1,'刘晨','男','2022245','6575','2016-04-06')"));
    query.exec(QString("insert into User2 values (2,'王敏','女','2022347','6432','2017-02-06')"));
    query.exec(QString("insert into User2 values (3,'张萌','女','2022147','6424','2018-02-06')"));
    return true;

   }
#endif // CONNECTION_H
