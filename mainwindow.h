#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editors/facilityeditor.h"

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
private:
    Ui::MainWindow *ui;
    FacilityEditor *fe = NULL;

};

#endif // MAINWINDOW_H
