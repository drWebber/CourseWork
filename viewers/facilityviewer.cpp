#include "facilityviewer.h"
#include "ui_facilityviewer.h"
#include "sql/sql.h"
#include <qdebug.h>

FacilityViewer::FacilityViewer(QWidget *parent) :
    AbstractTableView(parent),
    ui(new Ui::FacilityViewer)
{
    ui->setupUi(this);

    ui->cbType->addItems(Sql::getDistinctValues("facility", "type"));
    connect(ui->cbType, SIGNAL(currentTextChanged(QString)),
            this, SLOT(onFilterChanged()));
    connect(ui->sbCapacity, SIGNAL(valueChanged(int)),
            this, SLOT(onFilterChanged()));

    model->setTable("facility");
    tableView->setModel(model);
    ui->gridLayout->addWidget(tbnAddRow, 3, 0, 1, 1);
    ui->gridLayout->addWidget(tbnRemoveRow, 3, 1, 1, 1);
    ui->gridLayout->addWidget(tableView, 4, 0, 1, 5);
    tableView->hideColumn(0);
    model->select();
}

FacilityViewer::~FacilityViewer()
{
    delete ui;
}

void FacilityViewer::onFilterChanged()
{
    QString type = ui->cbType->currentText();
    if (type != "Все") {
        model->setFilter(QString("`type` = '%1' AND `capacity` > %2").arg(
                             type, ui->sbCapacity->text()));
    } else {
        model->setFilter(QString("`capacity` > %1").arg(ui->sbCapacity->text()));
    }
}
