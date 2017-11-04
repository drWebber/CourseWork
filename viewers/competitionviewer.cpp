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

    ui->cbSport->addItems(Sql::getDistinctValues("sport", "name"));
    ui->cbSponsor->addItems(Sql::getDistinctValues("competition", "sponsor"));
    ui->cbFacility->addItems(Sql::getDistinctValues("facility", "name"));
    connect(ui->cbSport, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterChanged()));
    connect(ui->cbSponsor, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterChanged()));
    connect(ui->cbFacility, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterChanged()));
}

CompetitionViewer::~CompetitionViewer()
{
    delete ui;
}

void CompetitionViewer::filterChanged()
{
    QStringList sl;
    QString sport = ui->cbSport->currentText();
    QString facility = ui->cbFacility->currentText();
    QString sponsor = ui->cbSponsor->currentText();
    bool hasFilter = false;
    if (sport != "Все") {
        QString q("SELECT ct.`id` "
                  "FROM `competition` AS ct "
                  "WHERE `sportID` IN("
                    "SELECT `id` "
                    "FROM `sport` "
                    "WHERE `name` = :sport"
                  ")");
        sl.append(Sql::getValuesList(q, QStringList(sport)));
        hasFilter = true;
    }
    if (facility != "Все") {
        QString q("SELECT ct.`id` "
                  "FROM `competition` AS ct "
                  "WHERE `facilityID` IN("
                    "SELECT `id` "
                    "FROM `facility` "
                    "WHERE `name` = :facility"
                  ")");
        sl.append(Sql::getValuesList(q, QStringList(facility)));
        hasFilter = true;
    }
    if (!sl.isEmpty() || hasFilter) {
        sl.removeDuplicates();
        QString idNum = sl.join(',');
        if (idNum.isEmpty())
            idNum = "-1";
        model->setFilter(QString("competition.`id` IN(%1)").arg(idNum));
    } else {
        model->setFilter("");
    }
}
