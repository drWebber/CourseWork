#include "facilityviewer.h"
#include "ui_facilityviewer.h"
#include "sql/sql.h"
#include <qdebug.h>

FacilityViewer::FacilityViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FacilityViewer)
{
    model = new QSqlTableModel(this);
    ui->setupUi(this);
    ui->tbnAddRow->setIcon(QIcon(QPixmap(":/img/images/Button-Add-icon.png")));
    ui->tbnDeleteRow->setIcon(QIcon(QPixmap(":/img/images/Button-Delete-icon.png")));
    setWindowTitle("Спортивные сооружения");

    ui->cbType->addItems(Sql::getDistinctValues("facility", "type"));

    model->setTable("facility");
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
    model->select();
}

FacilityViewer::~FacilityViewer()
{
    delete ui;
}

void FacilityViewer::on_tbnAddRow_clicked()
{
    model->insertRow(model->rowCount());
}

void FacilityViewer::on_tbnDeleteRow_clicked()
{
    model->removeRow(ui->tableView->currentIndex().row());
    model->select();
}

void FacilityViewer::on_cbType_currentTextChanged(const QString &arg1)
{
    if (arg1 != "Все") {
        model->setFilter(QString("`type` = '%1' AND `capacity` > %2").arg(
                             arg1, ui->sbCapacity->text()));
    } else {
        model->setFilter(QString("`capacity` > %1").arg(ui->sbCapacity->text()));
    }
}
