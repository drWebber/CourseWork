#include "facilityeditor.h"
#include "ui_facilityeditor.h"

#include <QSqlQuery>
#include <qsqlerror.h>
#include <qdebug.h>

FacilityEditor::FacilityEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FacilityEditor)
{
    ui->setupUi(this);
    setWindowTitle("Спортивные сооружения");
    QStringList typeList;
    QSqlQuery q;
    q.exec("SELECT DISTINCT `type` FROM `facility`");
    while (q.next()) {
        typeList.append(q.value(0).toString());
    }
    ui->cbType->addItems(typeList);
    model = new QSqlQueryModel(this);
    ui->tableView->setModel(model);
}

FacilityEditor::~FacilityEditor()
{
    delete model;
    delete ui;
}

void FacilityEditor::on_pbnExec_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM `facility` WHERE `type` = :type AND `capacity` >= :capacity");
    query.bindValue(":type", ui->cbType->currentText());
    query.bindValue(":capacity", ui->sbCapacity->value());
    query.exec();
    model->setQuery(query);
}
