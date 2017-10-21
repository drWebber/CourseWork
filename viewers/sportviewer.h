#ifndef SPORTVIEWER_H
#define SPORTVIEWER_H

#include <QWidget>
#include "abstracttableview.h"

namespace Ui {
class SportViewer;
}

class SportViewer : public AbstractTableView
{
    Q_OBJECT

public:
    explicit SportViewer(QString table, QList<int> *relColumns,
                         QList<QSqlRelation *> *relations, QWidget *parent = 0);
    ~SportViewer();
    enum COLUMNS {ID, NAME};
private:
    Ui::SportViewer *ui;
};

#endif // SPORTVIEWER_H
