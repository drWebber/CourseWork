#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sql/dbc.h"
#include <qmessagebox.h>
#include <qdebug.h>
#include "sportviewer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DBC dbc;
    dbc.connect();
    if (!dbc.isConnected()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка соединения с базой данных");
    }
    viewers = QStringList() << "actFacilityViewer";
    connect(ui->actFacilityViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    SportViewer *sv = new SportViewer();
    sv->show();
}

MainWindow::~MainWindow()
{
    delete fv;
    delete ui;
}

void MainWindow::onMenuTriggered()
{
    QString name = sender()->objectName();
    int indx = viewers.indexOf(QRegExp(name));
    if (indx < 0) return;
    switch (indx) {
    case FACILITY_VIEWER:
        fv = new FacilityViewer();
        fv->show();
        break;
    default:
        break;
    }
}
