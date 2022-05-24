#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QtWidgets>

#define DATABASE_NAME "bdQT"
#define CONNECT_TYPE "QODBC"

class Database
{
public:
    Database();
    bool openDataBase();
    void closeDataBase();
    bool restoreDataBase();

    bool insertVilles();

private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
