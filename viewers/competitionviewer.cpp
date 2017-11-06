#include "competitionviewer.h"
#include "ui_competitionviewer.h"
#include "sql/sql.h"

#include <qstringlist.h>
#include <qdebug.h>
#include <qsqlerror.h>

CompetitionViewer::CompetitionViewer(QString table, QList<int> *relColumns,
                                     QList<QSqlRelation *> *relations, QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::CompetitionViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);

    model->setHeaderData(DATE, Qt::Horizontal, "Дата");
    model->setHeaderData(NAME, Qt::Horizontal, "Название");
    model->setHeaderData(SPORT, Qt::Horizontal, "Вид спорта");
    model->setHeaderData(FACILITY, Qt::Horizontal, "Соружение");
    model->setHeaderData(SPONSOR, Qt::Horizontal, "Организатор");

    ui->cbSport->addItems(Sql::getDistinctValues("sport", "name"));
    ui->cbSponsor->addItems(Sql::getDistinctValues("competition", "sponsor"));
    ui->cbFacility->addItems(Sql::getDistinctValues("facility", "name"));
    connect(ui->cbSport, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterChanged()));
    connect(ui->cbSponsor, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterChanged()));
    connect(ui->cbFacility, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterChanged()));
    connect(ui->cbDateRange, SIGNAL(toggled(bool)),
            this, SLOT(onEnableDateRange(bool)));
    connect(ui->cbDateRange, SIGNAL(released()),
            this, SLOT(filterChanged()));
    connect(ui->deBegin, SIGNAL(dateChanged(QDate)),
            this, SLOT(filterChanged()));
    connect(ui->deEnd, SIGNAL(dateChanged(QDate)),
            this, SLOT(filterChanged()));
}

CompetitionViewer::~CompetitionViewer()
{
    delete ui;
}

void CompetitionViewer::filterChanged()
{
    QString sport = ui->cbSport->currentText();
    QString facility = ui->cbFacility->currentText();
    QString sponsor = ui->cbSponsor->currentText();

    if (sport != "Все") {
        QString q("SELECT ct.`id` "
                  "FROM `competition` AS ct "
                  "WHERE `sportID` IN("
                    "SELECT `id` "
                    "FROM `sport` "
                    "WHERE `name` = :sport"
                  ")");
        sl.append(Sql::getIdList(q, QStringList(sport)));
    }
    if (facility != "Все") {
        QString q("SELECT ct.`id` "
                  "FROM `competition` AS ct "
                  "WHERE `facilityID` IN("
                    "SELECT `id` "
                    "FROM `facility` "
                    "WHERE `name` = :facility"
                  ")");
        sl.append(Sql::getIdList(q, QStringList(facility)));
    }
    if (sponsor != "Все") {
        QString q("SELECT ct.`id` "
                  "FROM `competition` AS ct "
                  "WHERE `sponsor` = :sponsor");
        sl.append(Sql::getIdList(q, QStringList(sponsor)));
    }
    if (ui->cbDateRange->isChecked()) {
        QString q("SELECT ct.`id` "
                  "FROM `competition` AS ct "
                  "WHERE ct.`date` >= :rangeBegin "
                    "AND ct.`date` <= :rangeEnd");
        QString beginDate = ui->deBegin->date().toString("yyyy-MM-dd");
        QString endDate = ui->deEnd->date().toString("yyyy-MM-dd");
        sl.append(Sql::getIdList(q, QStringList() << beginDate << endDate));
    }
    setFilter("competition.`id`");
}

void CompetitionViewer::onEnableDateRange(bool enable)
{
    ui->deBegin->setEnabled(enable);
    ui->deEnd->setEnabled(enable);
}
