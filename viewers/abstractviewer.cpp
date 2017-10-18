#include "viewers/abstractviewer.h"
#include <qsqlquery.h>
#include <qsqlerror.h>
#include <qdebug.h>

AbstractViewer::AbstractViewer()
{
    model = new QSqlQueryModel();
}

void AbstractViewer::setModelQuery(QString query, QMap<QString, QString> bindMap)
{
    QSqlQuery q;
    if (bindMap.count() == 1) {
        query.replace(QRegExp("\\sWHERE.*"), "");
        q.exec(query);
    } else {
        q.prepare(query);
        QMapIterator<QString, QString> it(bindMap);
        while (it.hasNext()) {
            it.next();
            q.bindValue(it.key(), it.value());
        }
        q.exec();
    }
    model->setQuery(q);
}

QStringList AbstractViewer::getDistinctValues(QString table, QString column)
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
