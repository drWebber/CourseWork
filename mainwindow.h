#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlistwidget.h>
#include "sql/dbc.h"
#include "viewers/facilityviewer.h"
#include "viewers/athleteviewer.h"
#include "viewers/sportviewer.h"
#include "viewers/coachviewer.h"
#include "viewers/careerviewer.h"
#include "viewers/competitionviewer.h"
#include "viewers/prizeviewer.h"
#include "viewers/clubviewer.h"
#include "viewers/clubcompletitonviewer.h"
#include "viewers/participationviewer.h"
#include "viewers/clubsizeviewer.h"
#include "viewers/sponsorviewer.h"
#include "about.h"

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
    void onWgtClicked(QModelIndex index);
    void onHelpClicked();
private:
    DBC dbc;
    Ui::MainWindow *ui;
    FacilityViewer *fv = NULL;
    AthleteViewer *av = NULL;
    SportViewer *sv = NULL;
    CoachViewer *coachViewer = NULL;
    CareerViewer *careerViewer = NULL;
    CompetitionViewer *competitionViewer = NULL;
    PrizeViewer *pv = NULL;
    ClubViewer *clubViewer = NULL;
    ClubCompletitonViewer *cm = NULL;
    ParticipationViewer *pcv = NULL;
    ClubSizeViewer *csv = NULL;
    SponsorViewer *snv = NULL;
    About *about = NULL;
    QStringList viewers;
    enum VIEW_ID {FACILITY_VIEWER, ATHLETE_VIEWER, SPORT_VIEWER, COACH_VIEWER, CAREER_VIEWER,
                 COMPETITION_VIEWER, PRIZE_VIEWER, CLUB_VIEWER, CLUB_CMP_VIEWER, PARTICIPATION_VIEWER,
                 CLUB_SIZE_VIEWER, SPONSOR_VIEWER};
    const QStringList LIST_ITEMS =
        QStringList() << "Сооружения" << "Спортсмены" << "Виды спорта" << "Тренеры"
                      << "Карьера" << "Соревнования" << "Победители" << "Клубы"
                      << "Клубные соревнования" << "Участие" << "Численность" << "Организаторы";
    QListWidget *wgt;
    void showWidget(int index);
};

#endif // MAINWINDOW_H
