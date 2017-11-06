#include "clubsizeviewer.h"
#include "ui_clubsizeviewer.h"
#include <qsqlquery.h>

ClubSizeViewer::ClubSizeViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClubSizeViewer)
{
    ui->setupUi(this);
    model = new QSqlQueryModel(this);

    onFilterChanged();

    model->setHeaderData(NAME, Qt::Horizontal, "Клуб");
    model->setHeaderData(POPULATION, Qt::Horizontal, "Численность");

    connect(ui->cbDateRange, SIGNAL(toggled(bool)),
            this, SLOT(onDataRangeEnabled(bool)));
    connect(ui->cbDateRange, SIGNAL(toggled(bool)),
            this, SLOT(onFilterChanged()));
    connect(ui->deBegin, SIGNAL(dateChanged(QDate)),
            this, SLOT(onFilterChanged()));
    connect(ui->deEnd, SIGNAL(dateChanged(QDate)),
            this, SLOT(onFilterChanged()));
    ui->tableView->resizeColumnsToContents();

    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setStretchLastSection(true);
}

ClubSizeViewer::~ClubSizeViewer()
{
    delete ui;
}

void ClubSizeViewer::onFilterChanged()
{
    if (ui->cbDateRange->isChecked()) {
        QString beginDate = ui->deBegin->date().toString("yyyy-MM-dd");
        QString endDate = ui->deEnd->date().toString("yyyy-MM-dd");
        QString q("SELECT cb.`name`, num.`population` "
                  "FROM `club` AS cb "
                  "INNER JOIN ("
                      "SELECT cr.`clubID`, COUNT(cr.`athleteID`) AS population "
                      "FROM `career` AS cr "
                      "WHERE `clubID` IN("
                          "SELECT `homeClubID` "
                          "FROM `club_competition` "
                          "WHERE `date` >= '" + beginDate + "' AND `date` <= '" + endDate + "' "
                          "UNION "
                          "SELECT `awayClubID` "
                          "FROM `club_competition` "
                          "WHERE `date` >= '" + beginDate + "' AND `date` <= '" + endDate + "' "
                  ") "
                  "GROUP BY cr.`clubID`"
                  ") AS num ON cb.`id` = num.`clubID`");
        model->setQuery(q);
    } else {
        model->setQuery("SELECT cb.`name`, IFNULL(cl.`cn`, 0) "
                        "FROM `club` AS cb "
                        "LEFT JOIN ("
                            "SELECT cr.`clubID`, COUNT(cr.`athleteID`) AS cn "
                            "FROM `career` AS cr "
                            "GROUP BY cr.`clubID`"
                        ") AS cl ON cb.`id` = cl.`clubID` "
                        "WHERE cb.`id` <> 5");
        ui->tableView->setModel(model);
    }
}

void ClubSizeViewer::onDataRangeEnabled(bool status)
{
    ui->deBegin->setEnabled(status);
    ui->deEnd->setEnabled(status);
}
