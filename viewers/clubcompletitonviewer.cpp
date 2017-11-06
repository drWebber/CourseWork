#include "clubcompletitonviewer.h"
#include "ui_clubcompletitonviewer.h"

ClubCompletitonViewer::ClubCompletitonViewer(QString table, QList<int> *relColumns,
                                             QList<QSqlRelation *> *relations,
                                             QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::ClubCompletitonViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);
    model->setHeaderData(DATE, Qt::Horizontal, "Дата");
    model->setHeaderData(HOME_CLUB, Qt::Horizontal, "Дом. клуб");
    model->setHeaderData(AWAY_CLUB, Qt::Horizontal, "Прин. клуб");
    model->setHeaderData(SPORT, Qt::Horizontal, "Вид спорта");
    model->setHeaderData(FACILITY, Qt::Horizontal, "Сооружение");
    model->setHeaderData(SPONSOR, Qt::Horizontal, "Организатор");
}

ClubCompletitonViewer::~ClubCompletitonViewer()
{
    delete ui;
}
