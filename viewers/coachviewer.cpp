#include "coachviewer.h"
#include "ui_coachviewer.h"

CoachViewer::CoachViewer(QString table, QList<int> *relColumns,
                         QList<QSqlRelation *> *relations, QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::CoachViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);
    model->setHeaderData(FULL_NAME, Qt::Horizontal, "Фио");
    model->setHeaderData(SPORT, Qt::Horizontal, "Вид спорта");
}

CoachViewer::~CoachViewer()
{
    delete ui;
}
