#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sql/dbc.h"
#include <qmessagebox.h>
#include <qdebug.h>

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
    viewers = QStringList() << "actAthleteViewer";
    connect(ui->actFacilityEditor, SIGNAL(triggered(bool)),
            this, SLOT(onFacilityEditorCreate()));
    connect(ui->actAthleteViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
}

MainWindow::~MainWindow()
{
    delete fe;
    delete av;
    delete ui;
}

void MainWindow::onFacilityEditorCreate()
{
    fe = new FacilityEditor();
    fe->show();
}

void MainWindow::onMenuTriggered()
{
    QString name = sender()->objectName();
    int indx = viewers.indexOf(QRegExp(name));
    if (indx < 0) return;
    switch (indx) {
    case ATHLETE_VIEWER:
        av = new AthletesViewer();
        av->show();
        break;
    default:
        break;
    }
}
