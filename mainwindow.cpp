#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sql/dbc.h"
#include <qmessagebox.h>
#include <qdebug.h>
#include <qsqlquery.h>

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

    QSqlQuery q;
    q.exec("SET character_set_client=cp1251");
    q.exec("SET character_set_connection=UTF8");
    q.exec("SET character_set_results=cp1251");
    q.exec("SET character_set_database=UTF8");


    viewers = QStringList() << "actFacilityViewer" << "actAthleteViewer" << "actSportViewer"
                            << "actCoachViewer" << "actCareerViewer" << "actCompetitionViewer"
                            << "actPrizeViewer" << "actClubViewer" << "actClubCompetitionViewer"
                            << "actParticipationViewer";

    connect(ui->actFacilityViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    connect(ui->actAthleteViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    connect(ui->actSportViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    connect(ui->actCoachViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    connect(ui->actCareerViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    connect(ui->actCompetitionViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    connect(ui->actPrizeViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    connect(ui->actClubViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    connect(ui->actClubCompetitionViewer, SIGNAL(triggered(bool)),
            this, SLOT(onMenuTriggered()));
    connect(ui->actParticipationViewer, SIGNAL(triggered(bool)),
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
        fv = new FacilityViewer("facility", new QList<int>, new QList<QSqlRelation*>, ui->centralWidget);
        fv->show();
        setWindowTitle("Журнал \"Спортивные сооружения\"");
        break;
    case ATHLETE_VIEWER:
        av = new AthleteViewer("athlete", new QList<int>, new QList<QSqlRelation*>, ui->centralWidget);
        av->show();
        setWindowTitle("Журнал \"Спортсмены\"");
        break;
    case SPORT_VIEWER:
        sv = new SportViewer("sport", new QList<int>, new QList<QSqlRelation*>, ui->centralWidget);
        sv->show();
        setWindowTitle("Журнал \"Виды спорта\"");
        break;
    case COACH_VIEWER:
    {
        QList<int> *columns = new QList<int>();
        columns->append(CoachViewer::SPORT);
        QList<QSqlRelation*> *relations = new QList<QSqlRelation*>();
        relations->append(new QSqlRelation("sport", "id", "name"));
        coachViewer = new CoachViewer("coach", columns, relations, ui->centralWidget);
        coachViewer->show();
        setWindowTitle("Журнал \"Тренеры\"");
        delete columns;
        delete relations;
        break;
    }
    case CAREER_VIEWER:
    {
        QList<int> *columns = new QList<int>();
        columns->append(CareerViewer::ATHLETE);
        columns->append(CareerViewer::SPORT);
        columns->append(CareerViewer::COACH);
        columns->append(CareerViewer::CLUB);
        QList<QSqlRelation*> *relations = new QList<QSqlRelation*>();
        relations->append(new QSqlRelation("athlete", "id", "full_name"));
        relations->append(new QSqlRelation("sport", "id", "name"));
        relations->append(new QSqlRelation("coach", "id", "full_name"));
        relations->append(new QSqlRelation("club", "id", "name"));
        careerViewer = new CareerViewer("career", columns, relations, ui->centralWidget);
        careerViewer->show();
        setWindowTitle("Журнал \"Карьера спортсмена\"");
        delete columns;
        delete relations;
        break;
    }
    case COMPETITION_VIEWER:
    {
        QList<int> *columns = new QList<int>();
        columns->append(CompetitionViewer::SPORT);
        columns->append(CompetitionViewer::FACILITY);
        QList<QSqlRelation*> *relations = new QList<QSqlRelation*>();
        relations->append(new QSqlRelation("sport", "id", "name"));
        relations->append(new QSqlRelation("facility", "id", "name"));
        competitionViewer = new CompetitionViewer("competition", columns, relations, ui->centralWidget);
        competitionViewer->show();
        setWindowTitle("Журнал \"Соревнования\"");
        delete columns;
        delete relations;
        break;
    }
    case PRIZE_VIEWER:
    {
        QList<int> *columns = new QList<int>();
        columns->append(PrizeViewer::COMPETITION);
        columns->append(PrizeViewer::GOLD_MEDAL_ATH);
        columns->append(PrizeViewer::SILVER_MEDAL_ATH);
        columns->append(PrizeViewer::BRONZE_MEDAL_ATH);
        QList<QSqlRelation*> *relations = new QList<QSqlRelation*>();
        relations->append(new QSqlRelation("competition", "id", "name"));
        relations->append(new QSqlRelation("athlete", "id", "full_name"));
        relations->append(new QSqlRelation("athlete", "id", "full_name"));
        relations->append(new QSqlRelation("athlete", "id", "full_name"));
        pv = new PrizeViewer("prize", columns, relations, ui->centralWidget);
        pv->show();
        setWindowTitle("Журнал \"Призеры соревнований\"");
        delete columns;
        delete relations;
        break;
    }
    case CLUB_VIEWER:
    {
        QList<int> *columns = new QList<int>();
        columns->append(ClubViewer::SPORT);
        QList<QSqlRelation*> *relations = new QList<QSqlRelation*>();
        relations->append(new QSqlRelation("sport", "id", "name"));
        clubViewer = new ClubViewer("club", columns, relations, ui->centralWidget);
        clubViewer->show();
        setWindowTitle("Журнал \"Спортивные клубы\"");
        delete columns;
        delete relations;
        break;
    }
    case CLUB_CMP_VIEWER:
    {
        QList<int> *columns = new QList<int>();
        columns->append(ClubCompletitonViewer::HOME_CLUB);
        columns->append(ClubCompletitonViewer::AWAY_CLUB);
        columns->append(ClubCompletitonViewer::SPORT);
        columns->append(ClubCompletitonViewer::FACILITY);
        QList<QSqlRelation*> *relations = new QList<QSqlRelation*>();
        relations->append(new QSqlRelation("club", "id", "name"));
        relations->append(new QSqlRelation("club", "id", "name"));
        relations->append(new QSqlRelation("sport", "id", "name"));
        relations->append(new QSqlRelation("facility", "id", "name"));
        cm = new ClubCompletitonViewer("club_competition", columns, relations, ui->centralWidget);
        cm->show();
        setWindowTitle("Журнал \"Клубные соревнования\"");
        delete columns;
        delete relations;
        break;
    }
    case PARTICIPATION_VIEWER:
    {
        QList<int> *columns = new QList<int>();
        columns->append(ParticipationViewer::ATHLETE);
        columns->append(ParticipationViewer::COMPETITION);
        QList<QSqlRelation*> *relations = new QList<QSqlRelation*>();
        relations->append(new QSqlRelation("athlete", "id", "full_name"));
        relations->append(new QSqlRelation("competition", "id", "name"));
        pcv = new ParticipationViewer("participation", columns, relations, ui->centralWidget);
        pcv->show();
        setWindowTitle("Журнал \"Участие в соревнованиях\"");
        delete columns;
        delete relations;
        break;
    }
    default:
        break;
    }
}
