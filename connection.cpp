#include "connection.h"
#include <QDebug>
#include <QSqlError>

connection::connection() {}

bool connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={Oracle in XE};Dbq=localhost:1521/XE;Uid=kaabi;Pwd=kaabi;");


    if (db.open()) {
        test = true;
    } else {
        qDebug() << "Erreur ODBC:" << db.lastError().text();
    }

    return test;
}
