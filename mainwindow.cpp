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
   connect(ui->actFacilityEditor, SIGNAL(triggered(bool)),
           this, SLOT(onFacilityEditorCreate()));
}

MainWindow::~MainWindow()
{
    delete fe;
    delete ui;
}

void MainWindow::onFacilityEditorCreate()
{
    qDebug() << "here";
    fe = new FacilityEditor();
    fe->show();
}
