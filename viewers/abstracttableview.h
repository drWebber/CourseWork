#ifndef ABSTRACTTABLEVIEW_H
#define ABSTRACTTABLEVIEW_H

#include <QWidget>
#include <QSqlTableModel>
#include <qtableview.h>
#include <qtoolbutton.h>

class AbstractTableView : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractTableView(QWidget *parent = 0);
    ~AbstractTableView();
protected slots:
    void onTbnAddRow_clicked();
    void onTbnRemoveRow_clicked();
protected:
    QSqlTableModel *model;
    QTableView *tableView;
    QToolButton *tbnAddRow;
    QToolButton *tbnRemoveRow;
};

#endif // ABSTRACTTABLEVIEW_H
