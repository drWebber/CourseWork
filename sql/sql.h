#ifndef SQL_H
#define SQL_H
#include <qstringlist.h>

class Sql
{
public:
    Sql();
    static QStringList getDistinctValues(QString table, QString column);
    static QString getValuesLine(QString query, QStringList valsToBind);
};

#endif // SQL_H
