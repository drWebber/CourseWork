#ifndef ABSTRACTTABLEVIEW_H
#define ABSTRACTTABLEVIEW_H

#include <QWidget>
#include <qsqlrelationaltablemodel.h>
#include <qtableview.h>
#include <qtoolbutton.h>
#include <qgridlayout.h>
#include "tools/sequenselist.h"
#include "sql/sql.h"

class AbstractTableView : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractTableView(QString table, QList<int> *relColumns,
                               QList<QSqlRelation *> *relations, QWidget *parent = 0);
    ~AbstractTableView();
protected slots:
    void onTbnAddRow_clicked();
    void onTbnRemoveRow_clicked();
protected:
    QSqlRelationalTableModel *model;
    QTableView *tableView;
    QToolButton *tbnAddRow;
    QToolButton *tbnRemoveRow;
    SequenseList sl;
    void addStandardWidget(QGridLayout *gridLayout);
    void setFilter(QString filterCol, Sql::condition condition = Sql::IN);
private:
    QGridLayout *gridLayout;
    QHeaderView *header = NULL;
    QHBoxLayout *horizontalLayout;
};

#endif // ABSTRACTTABLEVIEW_H
