#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "viewers/facilityviewer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void onMenuTriggered();
private:
    Ui::MainWindow *ui;
    FacilityViewer *fv = NULL;
    QStringList viewers;
    enum VIEW_ID {FACILITY_VIEWER};
};

#endif // MAINWINDOW_H
