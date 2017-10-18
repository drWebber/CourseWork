#ifndef ABSTRACTVIEWER_H
#define ABSTRACTVIEWER_H
#include <qsqlquerymodel.h>

class AbstractViewer
{
public:
    AbstractViewer();
protected:
    void setModelQuery(QString query, QMap<QString, QString> bindMap);
    QStringList getDistinctValues(QString table, QString column);
    QSqlQueryModel *model;
};

#endif // ABSTRACTVIEWER_H
