#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    setWindowTitle("О программе");
    connect(ui->pbnOk, SIGNAL(clicked(bool)),
            this, SLOT(close()));
}

About::~About()
{
    delete ui;
}
