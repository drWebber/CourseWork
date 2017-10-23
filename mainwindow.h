#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "viewers/facilityviewer.h"
#include "viewers/athleteviewer.h"
#include "viewers/sportviewer.h"
#include "viewers/coachviewer.h"
#include "viewers/careerviewer.h"
#include "viewers/competitionviewer.h"
#include "viewers/prizeviewer.h"

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
    AthleteViewer *av = NULL;
    SportViewer *sv = NULL;
    CoachViewer *coachViewer = NULL;
    CareerViewer *careerViewer = NULL;
    CompetitionViewer *competitionViewer = NULL;
    PrizeViewer *pv = NULL;
    QStringList viewers;
    enum VIEW_ID {FACILITY_VIEWER, ATHLETE_VIEWER, SPORT_VIEWER, COACH_VIEWER, CAREER_VIEWER,
                 COMPETITION_VIEWER, PRIZE_VIEWER};
};

#endif // MAINWINDOW_H
