#ifndef CLUBVIEWER_H
#define CLUBVIEWER_H

#include <QWidget>
#include "abstracttableview.h"

namespace Ui {
class ClubViewer;
}

class ClubViewer : public AbstractTableView
{
    Q_OBJECT

public:
    explicit ClubViewer(QString table, QList<int> *relColumns,
                        QList<QSqlRelation *> *relations, QWidget *parent = 0);
    ~ClubViewer();
    enum COLUMNS {ID, NAME, SPORT};
private:
    Ui::ClubViewer *ui;
};

#endif // CLUBVIEWER_H
