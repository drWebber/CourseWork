#include "sql.h"

#include <qsqlquery.h>
#include <qsqlerror.h>
#include <qvariant.h>
#include <qdebug.h>

Sql::Sql()
{

}

QStringList Sql::getDistinctValues(QString table, QString column)
{
    QStringList values = QStringList() << "Все";
    QSqlQuery q;
    q.prepare(QString("SELECT DISTINCT %1 FROM %2").arg(column, table));
    if (!q.exec())
        qDebug() << "Ошибка выполения запроса:" << q.lastError();
    while (q.next())
        values.append(q.value(0).toString());
    return values;
}

QString Sql::getValuesLine(QString query, QStringList valsToBind)
{
    QString condition;
    QSqlQuery q;
    q.prepare(query);
    for (int i = 0; i < valsToBind.count(); ++i)
        q.bindValue(i, valsToBind.at(i));
    if (!q.exec())
        qDebug() << "Unable to execute query:" << query << " " << q.lastError().text();
    while (q.next())
         condition.append(q.value(0).toString() + ',');
    condition.chop(1);
    return condition;
}

QStringList Sql::getIdList(const QString query, const QStringList valsToBind)
{
    QStringList result;
    QSqlQuery q;
    q.prepare(query);
    for (int i = 0; i < valsToBind.count(); ++i)
        q.bindValue(i, valsToBind.at(i));
    if (!q.exec())
        qDebug() << "Unable to execute query:" << q.lastQuery() << " text: " << q.lastError().text();
    while (q.next())
         result.append(q.value(0).toString());
    return result;
}
