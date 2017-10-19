#include "sql.h"

#include <qsqlquery.h>
#include <qvariant.h>

Sql::Sql()
{

}

QStringList Sql::getDistinctValues(QString table, QString column)
{
    QStringList values = QStringList() << "Все";
    QSqlQuery q;
    q.prepare(QString("SELECT DISTINCT %1 FROM %2").arg(column, table));
    q.exec();
    while (q.next()) {
        values.append(q.value(0).toString());
    }
    return values;
}
