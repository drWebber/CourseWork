#include "competitionviewer.h"
#include "ui_competitionviewer.h"

CompetitionViewer::CompetitionViewer(QString table, QList<int> *relColumns,
                                     QList<QSqlRelation *> *relations, QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::CompetitionViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);
}

CompetitionViewer::~CompetitionViewer()
{
    delete ui;
}
