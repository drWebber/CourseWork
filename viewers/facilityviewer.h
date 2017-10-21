#ifndef FACILITYVIEWER_H
#define FACILITYVIEWER_H

#include <QWidget>
#include <qsqltablemodel.h>
#include "abstracttableview.h"

namespace Ui {
class FacilityViewer;
}

class FacilityViewer : public AbstractTableView
{
    Q_OBJECT

public:
    explicit FacilityViewer(QString table, QList<int> *relColumns,
                            QList<QSqlRelation *> *relations, QWidget *parent = 0);
    ~FacilityViewer();
    enum COLUMNS {ID, NAME, TYPE, ADDRESS, CAPACITY};
private slots:
    void onFilterChanged();
private:
    Ui::FacilityViewer *ui;
};

#endif // FACILITYVIEWER_H
