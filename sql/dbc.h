#ifndef DBC_H
#define DBC_H
#include <QtSql/qsqldatabase.h>


class DBC
{
public:
    DBC();
    void connect();
    bool isConnected();
private:
    QSqlDatabase db;
};

#endif // DBC_H
