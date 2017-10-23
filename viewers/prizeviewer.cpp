#include "prizeviewer.h"
#include "ui_prizeviewer.h"

PrizeViewer::PrizeViewer(QString table, QList<int> *relColumns,
                         QList<QSqlRelation *> *relations, QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::PrizeViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);
}

PrizeViewer::~PrizeViewer()
{
    delete ui;
}
