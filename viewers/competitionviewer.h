#ifndef COMPETITIONVIEWER_H
#define COMPETITIONVIEWER_H

#include <QWidget>
#include "abstracttableview.h"

namespace Ui {
class CompetitionViewer;
}

class CompetitionViewer : public AbstractTableView
{
    Q_OBJECT
public:
    explicit CompetitionViewer(QString table, QList<int> *relColumns,
                               QList<QSqlRelation *> *relations, QWidget *parent = 0);
    ~CompetitionViewer();
    enum COLUMNS {ID, DATE, NAME, SPORT, FACILITY, SPONSOR};
private slots:
    void filterChanged();
    void onEnableDateRange(bool enable);
private:
    Ui::CompetitionViewer *ui;
};

#endif // COMPETITIONVIEWER_H
