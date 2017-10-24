#ifndef CAREERVIEWER_H
#define CAREERVIEWER_H

#include <QWidget>
#include "abstracttableview.h"

namespace Ui {
class CareerViewer;
}

class CareerViewer : public AbstractTableView
{
    Q_OBJECT

public:
    explicit CareerViewer(QString table, QList<int> *relColumns,
                          QList<QSqlRelation *> *relations, QWidget *parent = 0);
    ~CareerViewer();
    enum COLUMNS{ID, ATHLETE, SPORT, CATEGORY, COACH, CLUB};
public slots:
    void onFilterChanged();
private:
    Ui::CareerViewer *ui;
};

#endif // CAREERVIEWER_H
