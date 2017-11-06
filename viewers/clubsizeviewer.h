#ifndef CLUBSIZEVIEWER_H
#define CLUBSIZEVIEWER_H

#include <QWidget>
#include <qsqlquerymodel.h>

namespace Ui {
class ClubSizeViewer;
}

class ClubSizeViewer : public QWidget
{
    Q_OBJECT

public:
    explicit ClubSizeViewer(QWidget *parent = 0);
    ~ClubSizeViewer();
    enum COLUMNS {NAME, POPULATION};
private slots:
    void onFilterChanged();
    void onDataRangeEnabled(bool status);
private:
    Ui::ClubSizeViewer *ui;
    QSqlQueryModel *model;
};

#endif // CLUBSIZEVIEWER_H
