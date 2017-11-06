#include "athleteviewer.h"
#include "ui_athleteviewer.h"
#include "sql/sql.h"
#include <qsqlquery.h>

#include <qdebug.h>
#include <qsqlerror.h>

AthleteViewer::AthleteViewer(QString table, QList<int> *relColumns,
                             QList<QSqlRelation *> *relations, QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::AthleteViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);
    model->setHeaderData(FULL_NAME, Qt::Horizontal, "Фио");
    model->setHeaderData(DOB, Qt::Horizontal, "Дата рождения");

    ui->cbSportType->addItems(Sql::getDistinctValues("sport", "name"));
    ui->cbCoach->addItems(Sql::getDistinctValues("coach", "full_name"));
    connect(ui->cbSportType, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(onFilterChanged()));
    connect(ui->cbCoach, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(onFilterChanged()));
    connect(ui->sbCategory, SIGNAL(valueChanged(QString)),
            this, SLOT(onFilterChanged()));
    connect(ui->cbDateRange, SIGNAL(toggled(bool)),
            this, SLOT(onDataRangeEnabled(bool)));
    connect(ui->cbDateRange, SIGNAL(toggled(bool)),
            this, SLOT(onFilterChanged()));
    connect(ui->deBegin, SIGNAL(dateChanged(QDate)),
            this, SLOT(onFilterChanged()));
    connect(ui->deEnd, SIGNAL(dateChanged(QDate)),
            this, SLOT(onFilterChanged()));
}

AthleteViewer::~AthleteViewer()
{
    delete ui;
}

void AthleteViewer::onFilterChanged()
{
    QString sport = ui->cbSportType->currentText();
    QString coach = ui->cbCoach->currentText();
    QString category = ui->sbCategory->text();

    if (category != "Все") {
        QString q("SELECT `athleteID` "
                  "FROM `career` "
                  "WHERE `category` >= :category ");
        sl.append(Sql::getIdList(q, QStringList(category)));
    }
    if (sport != "Все") {
        QString q("SELECT cr.`athleteID` "
                  "FROM `career` AS cr "
                  "WHERE `sportID` = ("
                    "SELECT sp.`id` "
                    "FROM `sport` AS sp "
                    "WHERE `name` = :sport"
                  ")");
        sl.append(Sql::getIdList(q, QStringList(sport)));
    }
    if (coach != "Все") {
        QString q("SELECT cr.`athleteID` "
                  "FROM `career` AS cr "
                  "WHERE `coachID` IN ("
                    "SELECT ch.`id` "
                    "FROM `coach` AS ch "
                    "WHERE `full_name` = :coach"
                  ")");
        sl.append(Sql::getIdList(q, QStringList(coach)));
    }
    if (ui->cbDateRange->isChecked()) {
        QString q("SELECT at.`id` "
                  "FROM `athlete` AS at "
                  "WHERE at.`id` NOT IN("
                      "SELECT ptc.`athleteID` "
                      "FROM `participation` AS ptc "
                      "WHERE ptc.`competitionID` IN("
                        "SELECT ct.`id` "
                        "FROM `competition` AS ct "
                        "WHERE date >= :beginDate "
                            "AND date <= :endDate"
                      ")"
                  ")");
        QString beginDate = ui->deBegin->date().toString("yyyy-MM-dd");
        QString endDate = ui->deEnd->date().toString("yyyy-MM-dd");
        sl.append(Sql::getIdList(q, QStringList() << beginDate << endDate));
    }
    setFilter("athlete.`id`");
}

void AthleteViewer::onDataRangeEnabled(bool status)
{
    ui->deBegin->setEnabled(status);
    ui->deEnd->setEnabled(status);
}
