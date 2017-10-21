#ifndef COACHVIEWER_H
#define COACHVIEWER_H

#include <QWidget>
#include "abstracttableview.h"

namespace Ui {
class CoachViewer;
}

class CoachViewer : public AbstractTableView
{
    Q_OBJECT

public:
    explicit CoachViewer(QString table, QList<int> *relColumns,
                         QList<QSqlRelation *> *relations, QWidget *parent = 0);
    ~CoachViewer();
    enum COLUMNS{ID, FULL_NAME, SPORT};
private:
    Ui::CoachViewer *ui;
};

#endif // COACHVIEWER_H
