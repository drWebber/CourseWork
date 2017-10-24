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
}

ClubCompletitonViewer::~ClubCompletitonViewer()
{
    delete ui;
}
