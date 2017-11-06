#include "prizeviewer.h"
#include "ui_prizeviewer.h"
#include "sql/sql.h"

#include <qdebug.h>

PrizeViewer::PrizeViewer(QString table, QList<int> *relColumns,
                         QList<QSqlRelation *> *relations, QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::PrizeViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);

    model->setHeaderData(COMPETITION, Qt::Horizontal, "Соревнование");
    model->setHeaderData(GOLD_MEDAL_ATH, Qt::Horizontal, "Золото");
    model->setHeaderData(SILVER_MEDAL_ATH, Qt::Horizontal, "Серебро");
    model->setHeaderData(BRONZE_MEDAL_ATH, Qt::Horizontal, "Бронза");

    ui->cmbCompetition->addItems(Sql::getDistinctValues("competition", "name"));
    connect(ui->cmbCompetition, SIGNAL(currentIndexChanged(int)),
            this, SLOT(onFilterChanged()));
}

PrizeViewer::~PrizeViewer()
{
    delete ui;
}

void PrizeViewer::onFilterChanged()
{
    QString competition = ui->cmbCompetition->currentText();
    if (competition != "Все") {
        QString q("SELECT pz.`id` "
                  "FROM `prize` AS pz "
                  "WHERE pz.`competitionID` = ("
                    "SELECT ct.`id` "
                    "FROM `competition` AS ct "
                    "WHERE ct.`name` = :competition"
                  ")");
        QStringList idList = Sql::getIdList(q, QStringList(competition));
        if (idList.isEmpty()) {
            model->setFilter("prize.`id` = '-1'");
        } else {
            model->setFilter(QString("prize.`id` IN(%1)").arg(idList.join(',')));
        }
    } else {
        model->setFilter("");
    }

}
