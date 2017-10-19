#ifndef FACILITYVIEWER_H
#define FACILITYVIEWER_H

#include <QWidget>
#include <qsqlquerymodel.h>

namespace Ui {
class FacilityViewer;
}

class FacilityViewer : public QWidget
{
    Q_OBJECT

public:
    explicit FacilityViewer(QWidget *parent = 0);
    ~FacilityViewer();
public slots:
    void onFilterChanged();
private:
    Ui::FacilityViewer *ui;
    QSqlQueryModel *model;
};

#endif // FACILITYVIEWER_H
