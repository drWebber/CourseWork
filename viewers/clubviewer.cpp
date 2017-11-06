#include "clubviewer.h"
#include "ui_clubviewer.h"

ClubViewer::ClubViewer(QString table, QList<int> *relColumns,
                       QList<QSqlRelation *> *relations, QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::ClubViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);
    model->setHeaderData(NAME, Qt::Horizontal, "Название");
    model->setHeaderData(SPORT, Qt::Horizontal, "Вид спорта");
}

ClubViewer::~ClubViewer()
{
    delete ui;
}
