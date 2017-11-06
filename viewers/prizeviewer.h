#ifndef PRIZEVIEWER_H
#define PRIZEVIEWER_H

#include <QWidget>
#include "abstracttableview.h"

namespace Ui {
class PrizeViewer;
}

class PrizeViewer : public AbstractTableView
{
    Q_OBJECT

public:
    explicit PrizeViewer(QString table, QList<int> *relColumns,
                         QList<QSqlRelation *> *relations, QWidget *parent = 0);
    ~PrizeViewer();
    enum COLUMNS {ID, COMPETITION, GOLD_MEDAL_ATH, SILVER_MEDAL_ATH, BRONZE_MEDAL_ATH};
private slots:
    void onFilterChanged();
private:
    Ui::PrizeViewer *ui;
};

#endif // PRIZEVIEWER_H
