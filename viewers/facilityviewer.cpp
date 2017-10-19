#include "facilityviewer.h"
#include "ui_facilityviewer.h"
#include <qdebug.h>
#include <qsqlquery.h>
#include "sql/sql.h"

FacilityViewer::FacilityViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FacilityViewer)
{
    ui->setupUi(this);
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM `facility`");

    ui->cbFacilityType->addItems(Sql::getDistinctValues("facility", "type"));
    connect(ui->cbFacilityType, SIGNAL(currentTextChanged(QString)),
            this, SLOT(onFilterChanged()));
    connect(ui->sbCapacity, SIGNAL(valueChanged(int)),
            this, SLOT(onFilterChanged()));
    ui->tableView->setModel(model);
}

FacilityViewer::~FacilityViewer()
{
    delete ui;
}

void FacilityViewer::onFilterChanged()
{
    bool hasChanges = false;
    QString query("SELECT * FROM `facility` WHERE");
    if (ui->cbFacilityType->currentText() != "Все") {
        hasChanges = true;
        query.append(" `type` = '" + ui->cbFacilityType->currentText() + "'");
    }
    if (ui->sbCapacity->value() > 0) {
        if (hasChanges) query.append("AND");
        hasChanges = true;
        query.append(" `capacity` >= " + ui->sbCapacity->text());
    }
    if (hasChanges) {
        model->setQuery(query);
    }
}
