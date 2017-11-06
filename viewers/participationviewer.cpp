#include "participationviewer.h"
#include "ui_participationviewer.h"

ParticipationViewer::ParticipationViewer(QString table, QList<int> *relColumns,
                                         QList<QSqlRelation *> *relations,
                                         QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::ParticipationViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);

    model->setHeaderData(ATHLETE, Qt::Horizontal, "Спортсмен");
    model->setHeaderData(COMPETITION, Qt::Horizontal, "Соревнование");
}

ParticipationViewer::~ParticipationViewer()
{
    delete ui;
}
