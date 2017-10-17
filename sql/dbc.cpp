#include "dbc.h"

DBC::DBC()
{

}

void DBC::connect()
{
    db = QSqlDatabase::addDatabase("QMYSQL3");

    db.setHostName("localhost");
    db.setDatabaseName("arena");
    db.setUserName("root");
    db.open();
}

bool DBC::isConnected()
{
    return db.isOpen() ? true : false;
}

