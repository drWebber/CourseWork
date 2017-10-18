#include "athletesviewer.h"
#include "ui_athletesviewer.h"

AthletesViewer::AthletesViewer(QWidget *parent) :
    QWidget(parent), AbstractViewer(),
    ui(new Ui::AthletesViewer)
{
    ui->setupUi(this);
    ui->cbSport->addItems(getDistinctValues("sport", "name"));
}

AthletesViewer::~AthletesViewer()
{
    delete ui;
}
