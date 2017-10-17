#ifndef FACILITYEDITOR_H
#define FACILITYEDITOR_H

#include <QWidget>
#include <qsqlquerymodel.h>

namespace Ui {
class FacilityEditor;
}

class FacilityEditor : public QWidget
{
    Q_OBJECT

public:
    explicit FacilityEditor(QWidget *parent = 0);
    ~FacilityEditor();
    QSqlQueryModel *model;

private slots:
    void on_pbnExec_clicked();

private:
    Ui::FacilityEditor *ui;
};

#endif // FACILITYEDITOR_H
