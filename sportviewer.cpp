#include "sportviewer.h"
#include "ui_sportviewer.h"

SportViewer::SportViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SportViewer)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("sport");
//    ui->tableView->setModel(model);
//    model->setFilter("`id` = (SELECT `id` FROM `facility` LIMIT 1)");
    model->select();

    rel = new QSqlRelationalTableModel();
    rel->setTable("facility");
    rel->setRelation(0, QSqlRelation("sport", "id", "name"));
    ui->tableView->setModel(rel);
    rel->select();
}

SportViewer::~SportViewer()
{
    delete ui;
}
