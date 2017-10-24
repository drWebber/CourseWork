#ifndef PARTICIPATIONVIEWER_H
#define PARTICIPATIONVIEWER_H

#include <QWidget>
#include "abstracttableview.h"

namespace Ui {
class ParticipationViewer;
}

class ParticipationViewer : public AbstractTableView
{
    Q_OBJECT

public:
    explicit ParticipationViewer(QString table, QList<int> *relColumns,
                                 QList<QSqlRelation *> *relations, QWidget *parent = 0);
    ~ParticipationViewer();
    enum COLUMNS {ID, ATHLETE, COMPETITION};
private:
    Ui::ParticipationViewer *ui;
};

#endif // PARTICIPATIONVIEWER_H
