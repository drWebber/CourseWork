#ifndef SQL_H
#define SQL_H
#include <qstringlist.h>

class Sql
{
public:
    Sql();
    static QStringList getDistinctValues(QString table, QString column);
    static QString getValuesLine(QString query, QStringList valsToBind);
    static QStringList getIdList(const QString query, const QStringList valsToBind);

    enum condition{IN, NOT_IN};
};

#endif // SQL_H
