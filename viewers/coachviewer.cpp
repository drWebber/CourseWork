#include "coachviewer.h"
#include "ui_coachviewer.h"
#include "sql/sql.h"

#include <qdebug.h>
#include <qsqlerror.h>

CoachViewer::CoachViewer(QString table, QList<int> *relColumns,
                         QList<QSqlRelation *> *relations, QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::CoachViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);

    model->setHeaderData(FULL_NAME, Qt::Horizontal, "Фио");
    model->setHeaderData(SPORT, Qt::Horizontal, "Вид спорта");

    ui->cmbAthlete->addItems(Sql::getDistinctValues("athlete", "full_name"));
    connect(ui->cmbAthlete, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterChanged()));

    ui->cmbSport->addItems(Sql::getDistinctValues("sport", "name"));
    connect(ui->cmbSport, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterChanged()));
}

CoachViewer::~CoachViewer()
{
    delete ui;
}

void CoachViewer::filterChanged()
{
    QString athlete = ui->cmbAthlete->currentText();
    QString sport = ui->cmbSport->currentText();
    if (athlete != "Все") {
        QString q("SELECT `coachID` "
                  "FROM `career` "
                  "WHERE `athleteID` = "
                    "(SELECT `id` "
                    "FROM `athlete` "
                    "WHERE `full_name` = :athlete)");
        sl.append(Sql::getIdList(q, QStringList(athlete)));
    }
    if (sport != "Все") {
        QString q("SELECT ch.`id` "
                  "FROM `coach` AS ch "
                  "WHERE ch.`sportID` = ("
                    "SELECT `id` "
                    "FROM `sport` "
                    "WHERE `name` = :sport"
                  ")");
        sl.append(Sql::getIdList(q, QStringList(sport)));
    }
    setFilter("coach.`id`");
}
