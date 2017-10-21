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

QString Sql::getValuesLine(QString query, QStringList valsToBind)
{
    QString condition;
    QSqlQuery q;
    q.prepare(query);
    for (int i = 0; i < valsToBind.count(); ++i) {
        q.bindValue(i, valsToBind.at(i));
    }
    q.exec();
    while (q.next()) {
         condition.append(q.value(0).toString() + ',');
    }
    condition.chop(1);
    return condition;
}
