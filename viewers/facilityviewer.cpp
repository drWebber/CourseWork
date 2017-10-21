#include "facilityviewer.h"
#include "ui_facilityviewer.h"
#include "sql/sql.h"
#include <qdebug.h>

FacilityViewer::FacilityViewer(QString table, QList<int> *relColumns,
                               QList<QSqlRelation *> *relations, QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::FacilityViewer)
{
    ui->setupUi(this);

    ui->cbType->addItems(Sql::getDistinctValues("facility", "type"));

    addStandardWidget(ui->gridLayout);

    model->setHeaderData(TYPE, Qt::Horizontal, "Тип");
    model->setHeaderData(NAME, Qt::Horizontal, "Название");
    model->setHeaderData(ADDRESS, Qt::Horizontal, "Адрес");
    model->setHeaderData(CAPACITY, Qt::Horizontal, "Вместительность");

    connect(ui->cbType, SIGNAL(currentTextChanged(QString)),
            this, SLOT(onFilterChanged()));
    connect(ui->sbCapacity, SIGNAL(valueChanged(int)),
            this, SLOT(onFilterChanged()));
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
        model->setFilter(QString("`capacity` >= %1").arg(ui->sbCapacity->text()));
    }
}
