#ifndef FACILITYVIEWER_H
#define FACILITYVIEWER_H

#include <QWidget>
#include <qsqltablemodel.h>

namespace Ui {
class FacilityViewer;
}

class FacilityViewer : public QWidget
{
    Q_OBJECT

public:
    explicit FacilityViewer(QWidget *parent = 0);
    ~FacilityViewer();

private slots:
    void on_tbnAddRow_clicked();
    void on_tbnDeleteRow_clicked();
    void on_cbType_currentTextChanged(const QString &arg1);

private:
    Ui::FacilityViewer *ui;
    QSqlTableModel *model;
};

#endif // FACILITYVIEWER_H
