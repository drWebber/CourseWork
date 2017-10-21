#ifndef ABSTRACTTABLEVIEW_H
#define ABSTRACTTABLEVIEW_H

#include <QWidget>
#include <qsqlrelationaltablemodel.h>
#include <qtableview.h>
#include <qtoolbutton.h>
#include <qgridlayout.h>

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
    void addStandardWidget(QGridLayout *gridLayout);
private:
    QGridLayout *gridLayout;
    QHeaderView *header = NULL;
};

#endif // ABSTRACTTABLEVIEW_H
