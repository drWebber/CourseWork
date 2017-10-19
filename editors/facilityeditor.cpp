#include "facilityeditor.h"
#include "ui_facilityeditor.h"

FacilityEditor::FacilityEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FacilityEditor)
{
    ui->setupUi(this);
}

FacilityEditor::~FacilityEditor()
{
    delete ui;
}
