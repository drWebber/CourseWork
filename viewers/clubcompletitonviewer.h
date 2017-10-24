#ifndef CLUBCOMPLETITONVIEWER_H
#define CLUBCOMPLETITONVIEWER_H

#include <QWidget>
#include "abstracttableview.h"

namespace Ui {
class ClubCompletitonViewer;
}

class ClubCompletitonViewer : public AbstractTableView
{
    Q_OBJECT

public:
    explicit ClubCompletitonViewer(QString table, QList<int> *relColumns,
                                   QList<QSqlRelation *> *relations, QWidget *parent = 0);
    ~ClubCompletitonViewer();
    enum COLUMNS{ID, DATE, HOME_CLUB, AWAY_CLUB, SPORT, FACILITY, SPONSOR};
private:
    Ui::ClubCompletitonViewer *ui;
};

#endif // CLUBCOMPLETITONVIEWER_H
