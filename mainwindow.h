#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editors/facilityeditor.h"
#include "viewers/athletesviewer.h"

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
    void onFacilityEditorCreate();
    void onMenuTriggered();
private:
    Ui::MainWindow *ui;
    FacilityEditor *fe = NULL;
    QStringList viewers;
    AthletesViewer *av = NULL;
    enum VIEW_ID {ATHLETE_VIEWER};
};

#endif // MAINWINDOW_H
