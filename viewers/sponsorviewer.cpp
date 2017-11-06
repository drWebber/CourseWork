#include "sponsorviewer.h"
#include "ui_sponsorviewer.h"

SponsorViewer::SponsorViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SponsorViewer)
{
    ui->setupUi(this);
    model = new QSqlQueryModel(this);
    onFilterChanged();

    model->setHeaderData(SPONSOR, Qt::Horizontal, "Организатор");
    model->setHeaderData(COMPETITION_NUM, Qt::Horizontal, "Проведенные соревнования");

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

SponsorViewer::~SponsorViewer()
{
    delete ui;
}

void SponsorViewer::onFilterChanged()
{
    if (ui->cbDateRange->isChecked()) {
        QString beginDate = ui->deBegin->date().toString("yyyy-MM-dd");
        QString endDate = ui->deEnd->date().toString("yyyy-MM-dd");
        model->setQuery("SELECT `sponsor`, COUNT(id) "
                        "FROM `competition` "
                        "WHERE `date` >= '" + beginDate + "' "
                            "AND `date` <= '" + endDate + "' "
                        "GROUP BY `sponsor`");
    } else {
        model->setQuery("SELECT `sponsor`, COUNT(id) "
                        "FROM `competition` "
                        "GROUP BY `sponsor`");
        ui->tableView->setModel(model);
    }
}

void SponsorViewer::onDataRangeEnabled(bool status)
{
    ui->deBegin->setEnabled(status);
    ui->deEnd->setEnabled(status);
}
