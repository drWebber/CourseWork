#include "coachviewer.h"
#include "ui_coachviewer.h"
#include "sql/sql.h"

#include <qdebug.h>
#include <qsqlerror.h>

CoachViewer::CoachViewer(QString table, QList<int> *relColumns,
                         QList<QSqlRelation *> *relations, QWidget *parent) :
    AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::CoachViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);

    model->setHeaderData(FULL_NAME, Qt::Horizontal, "Фио");
    model->setHeaderData(SPORT, Qt::Horizontal, "Вид спорта");

    ui->cbAthlete->addItems(Sql::getDistinctValues("athlete", "full_name"));
    connect(ui->cbAthlete, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterChanged()));
}

CoachViewer::~CoachViewer()
{
    delete ui;
}

void CoachViewer::filterChanged()
{
    QString athlete = ui->cbAthlete->currentText();
    if (athlete != "Все") {
        QString q("SELECT `coachID` "
                  "FROM `career` "
                  "WHERE `athleteID` = "
                    "(SELECT `id` "
                    "FROM `athlete` "
                    "WHERE `full_name` = '" + athlete + "')");
        QString idLine = Sql::getValuesLine(q, QStringList());
        if (!idLine.isEmpty())
            model->setFilter(QString("coach.`id` IN(%1)").arg(idLine));
    } else {
        model->setFilter("");
    }
}
