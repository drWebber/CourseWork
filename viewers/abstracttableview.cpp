#include "abstracttableview.h"
#include <qdebug.h>


AbstractTableView::AbstractTableView(QWidget *parent) :
    QWidget(parent)
{
    tbnAddRow = new QToolButton(parent);
    tbnRemoveRow = new QToolButton(parent);
    tbnAddRow->setIcon(QIcon(QPixmap(":/img/images/Button-Add-icon.png")));
    tbnRemoveRow->setIcon(QIcon(QPixmap(":/img/images/Button-Delete-icon.png")));

    model = new QSqlTableModel();
    tableView = new QTableView();

    connect(tbnAddRow, SIGNAL(clicked(bool)),
            this, SLOT(onTbnAddRow_clicked()));
    connect(tbnRemoveRow, SIGNAL(clicked(bool)),
            this, SLOT(onTbnRemoveRow_clicked()));
}

AbstractTableView::~AbstractTableView()
{
    delete model;
    delete tableView;
}

void AbstractTableView::onTbnAddRow_clicked()
{
    model->insertRow(model->rowCount());
}

void AbstractTableView::onTbnRemoveRow_clicked()
{
    model->removeRow(tableView->currentIndex().row());
    model->select();
}

