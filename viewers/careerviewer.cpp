#include "careerviewer.h"
#include "ui_careerviewer.h"

CareerViewer::CareerViewer(QString table, QList<int> *relColumns,
                           QList<QSqlRelation *> *relations, QWidget *parent) :
  AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::CareerViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);
    model->setHeaderData(ATHLETE, Qt::Horizontal, "Спортсмен");
    model->setHeaderData(SPORT, Qt::Horizontal, "Вид спорта");
    model->setHeaderData(CATEGORY, Qt::Horizontal, "Разряд");
    model->setHeaderData(COACH, Qt::Horizontal, "Тренер");
    model->setHeaderData(CLUB, Qt::Horizontal, "Клуб");
}

CareerViewer::~CareerViewer()
{
    delete ui;
}
