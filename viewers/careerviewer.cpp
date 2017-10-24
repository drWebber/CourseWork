#include "careerviewer.h"
#include "ui_careerviewer.h"
#include "sql/sql.h"

CareerViewer::CareerViewer(QString table, QList<int> *relColumns,
                           QList<QSqlRelation *> *relations, QWidget *parent) :
  AbstractTableView(table, relColumns, relations, parent),
    ui(new Ui::CareerViewer)
{
    ui->setupUi(this);
    addStandardWidget(ui->gridLayout);
    model->setHeaderData(ATHLETE, Qt::Horizontal, "Спортсмен");
    model->setHeaderData(SPORT, Qt::Horizontal, "Вид спорта");
    model->setHeaderData(CATEGORY, Qt::Horizontal, "Разряд");
    model->setHeaderData(COACH, Qt::Horizontal, "Тренер");
    model->setHeaderData(CLUB, Qt::Horizontal, "Клуб");
    connect(ui->cbMultiSport, SIGNAL(stateChanged(int)),
            this, SLOT(onFilterChanged()));
}

CareerViewer::~CareerViewer()
{
    delete ui;
}

void CareerViewer::onFilterChanged()
{
    if (ui->cbMultiSport->isChecked()) {
        QString q("SELECT `athleteID`"
                  "FROM `career`"
                  "GROUP BY `athleteID`"
                  "HAVING COUNT(`athleteID`) > 1");
        QString idLine = Sql::getValuesLine(q, QStringList());
        model->setFilter(QString("`athleteID` IN(%1)").arg(idLine));
    } else {
        model->setFilter("");
    }
}
