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
            this, SLOT(filterChanged()));
    connect(ui->cbCoach, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(filterChanged()));
    connect(ui->sbCategory, SIGNAL(valueChanged(QString)),
            this, SLOT(filterChanged()));
}

AthleteViewer::~AthleteViewer()
{
    delete ui;
}

void AthleteViewer::filterChanged()
{
    QString innerQuery, outerQuery;
    QStringList vals;
    QString sport = ui->cbSportType->currentText();
    QString coach = ui->cbCoach->currentText();
    if (sport != "Все" && coach != "Все") {
        innerQuery.append("SELECT `athleteID` FROM `career` "
                          "WHERE `sportID` = (SELECT `id` FROM `sport` WHERE name = :sport) "
                          "AND `category` >= :category "
                          "AND `coachID` = (SELECT `id` FROM `coach` WHERE full_name = :coach)");
        vals = QStringList() << sport << ui->sbCategory->text() << coach;
    } else {
        if (sport != "Все") {
            innerQuery.append("SELECT `athleteID` FROM `career` "
                              "WHERE `sportID` = (SELECT `id` FROM `sport` WHERE name = :sport) "
                              "AND `category` >= :category");
            vals = QStringList() << sport << ui->sbCategory->text();
        } else if (coach != "Все") {
            innerQuery.append("SELECT `athleteID` FROM `career` "
                              "WHERE `category` >= :category "
                              "AND `coachID` = (SELECT `id` FROM `coach` WHERE full_name = :coach)");
            vals = QStringList() << ui->sbCategory->text() << coach;
        } else {
            innerQuery.append("SELECT `athleteID` FROM `career` WHERE `category` >= :category");
            vals = QStringList() << ui->sbCategory->text();
        }
    }
    outerQuery.append(Sql::getValuesLine(innerQuery, vals));
    if (outerQuery.isEmpty()) {
        model->setFilter("0"); // WHERE 0, т.к. нет записей, соответствующих критериям отбора
    } else {
        model->setFilter(QString("`id` IN(%1)").arg(outerQuery));
    }
}
