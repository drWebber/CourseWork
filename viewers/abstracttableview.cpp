#include "abstracttableview.h"
#include <QSqlRelationalDelegate>
#include <qdebug.h>
#include <qheaderview.h>
#include <QListIterator>
#include <qsqlerror.h>
#include <qmessagebox.h>

AbstractTableView::AbstractTableView(QString table, QList<int> *relColumns,
                                     QList<QSqlRelation *> *relations, QWidget *parent) :
    QWidget(parent)
{
    tbnAddRow = new QToolButton(parent);
    tbnRemoveRow = new QToolButton(parent);
    tbnAddRow->setIcon(QIcon(QPixmap(":/img/images/Button-Add-icon.png")));
    tbnRemoveRow->setIcon(QIcon(QPixmap(":/img/images/Button-Delete-icon.png")));

    model = new QSqlRelationalTableModel();
    model->setTable(table);
    if (relations->count() > 0) {
        int counter = 0;
        QListIterator<QSqlRelation *> it(*relations);
        while (it.hasNext()) {
            model->setRelation(relColumns->at(counter++), *it.next());
        }
    }
    model->select();

    tableView = new QTableView();
    tableView->setModel(model);
    tableView->setItemDelegate(new QSqlRelationalDelegate(tableView));
    tableView->hideColumn(0);
    tableView->setSortingEnabled(true);
    tableView->resizeColumnsToContents();

    QHeaderView *header = tableView->horizontalHeader();
    header->setStretchLastSection(true);

    connect(tbnAddRow, SIGNAL(clicked(bool)),
            this, SLOT(onTbnAddRow_clicked()));
    connect(tbnRemoveRow, SIGNAL(clicked(bool)),
            this, SLOT(onTbnRemoveRow_clicked()));
}

AbstractTableView::~AbstractTableView()
{
    delete model;
    delete header;
    delete tableView;
}

void AbstractTableView::onTbnAddRow_clicked()
{
    model->insertRow(model->rowCount());
}

void AbstractTableView::onTbnRemoveRow_clicked()
{
    model->removeRow(tableView->currentIndex().row());
    QSqlError err = model->lastError();
    if (err.number() == 1451) {
        QMessageBox::warning(this, "Ошибка удаления записи", err.text());
    }
    model->select();
}

void AbstractTableView::addStandardWidget(QGridLayout *gridLayout)
{
    gridLayout->addWidget(tbnAddRow, 3, 0, 1, 1);
    gridLayout->addWidget(tbnRemoveRow, 3, 1, 1, 1);
    gridLayout->addWidget(tableView, 4, 0, 1, 8);
}

