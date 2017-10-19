#ifndef SQL_H
#define SQL_H
#include <qstringlist.h>

class Sql
{
public:
    Sql();
    static QStringList getDistinctValues(QString table, QString column);
};

#endif // SQL_H
