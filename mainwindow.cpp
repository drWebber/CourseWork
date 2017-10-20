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
    viewers = QStringList() << "actFacilityViewer" << "actAthleteViewer";
    connect(ui->actFacilityViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    connect(ui->actAthleteViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    resize(640, 480);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onMenuTriggered()
{
    QString name = sender()->objectName();
    int indx = viewers.indexOf(QRegExp(name));
    if (indx < 0) return;
    QObjectList children = ui->centralWidget->children();
    foreach (QObject *child, children) {
        child->deleteLater();
    }
    switch (indx) {
    case FACILITY_VIEWER:
        fv = new FacilityViewer(ui->centralWidget);
        fv->show();
        setWindowTitle("Журнал \"Спортивные сооружения\"");
        break;
    case ATHLETE_VIEWER:
        av = new AthleteViewer(ui->centralWidget);
        av->show();
        setWindowTitle("Журнал \"Спортсмены\"");
        break;
    default:
        break;
    }
}
