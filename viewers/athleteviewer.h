#ifndef ATHLETEVIEWER_H
#define ATHLETEVIEWER_H

#include <QWidget>
#include "abstracttableview.h"

namespace Ui {
class AthleteViewer;
}

class AthleteViewer : public AbstractTableView
{
    Q_OBJECT

public:
    explicit AthleteViewer(QString table, QList<int> *relColumns,
                           QList<QSqlRelation *> *relations, QWidget *parent = 0);
    ~AthleteViewer();
    enum COLUMNS {ID, FULL_NAME, DOB};
private slots:
    void onFilterChanged();
    void onDataRangeEnabled(bool status);
private:
    Ui::AthleteViewer *ui;
};

#endif // ATHLETEVIEWER_H
