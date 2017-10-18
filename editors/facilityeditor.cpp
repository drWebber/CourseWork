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
    QStringList typeList = QStringList() << "Все";
    QSqlQuery q;
    q.exec("SELECT DISTINCT `type` FROM `facility`");
    while (q.next()) {
        typeList.append(q.value(0).toString());
    }
    ui->cbType->addItems(typeList);
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM `facility`");
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
    resize(640, 480);
}

FacilityEditor::~FacilityEditor()
{
    delete model;
    delete ui;
}

void FacilityEditor::on_pbnExec_clicked()
{
    QSqlQuery query;
    QString facility = ui->cbType->currentText();
    if (facility == "Все") {
        query.prepare("SELECT * FROM `facility` WHERE `capacity` > :capacity");
    } else {
        query.prepare("SELECT * FROM `facility` WHERE `type` = :type AND `capacity` > :capacity");
        query.bindValue(":type", facility);
    }
    query.bindValue(":capacity", ui->sbCapacity->value());
    query.exec();
    model->setQuery(query);
}
