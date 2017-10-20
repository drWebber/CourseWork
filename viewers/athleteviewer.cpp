#include "athleteviewer.h"
#include "ui_athleteviewer.h"

AthleteViewer::AthleteViewer(QWidget *parent) :
    AbstractTableView(parent),
    ui(new Ui::AthleteViewer)
{
    ui->setupUi(this);
    model->setTable("athlete");
    tableView->setModel(model);
    ui->gridLayout->addWidget(tbnAddRow, 3, 0, 1, 1);
    ui->gridLayout->addWidget(tbnRemoveRow, 3, 1, 1, 1);
    ui->gridLayout->addWidget(tableView, 4, 0, 1, 3);
    model->select();
}

AthleteViewer::~AthleteViewer()
{
    delete ui;
}
