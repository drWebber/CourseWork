#include "sportviewer.h"
#include "ui_sportviewer.h"

SportViewer::SportViewer(QString table, QList<int> *relColumns,
                         QList<QSqlRelation *> *relations, QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::SportViewer)
{
    ui->setupUi(this);

    addStandardWidget(ui->gridLayout);

    model->setHeaderData(NAME, Qt::Horizontal, "Вид");
}

SportViewer::~SportViewer()
{
    delete ui;
}
