#ifndef SPORTVIEWER_H
#define SPORTVIEWER_H

#include <QWidget>
#include <qsqltablemodel.h>
#include <qsqlrelationaltablemodel.h>

namespace Ui {
class SportViewer;
}

class SportViewer : public QWidget
{
    Q_OBJECT

public:
    explicit SportViewer(QWidget *parent = 0);
    ~SportViewer();

private:
    Ui::SportViewer *ui;
    QSqlTableModel *model;
    QSqlRelationalTableModel *rel;
};

#endif // SPORTVIEWER_H
