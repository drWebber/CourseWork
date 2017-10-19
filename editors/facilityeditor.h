#ifndef FACILITYEDITOR_H
#define FACILITYEDITOR_H

#include <QWidget>

namespace Ui {
class FacilityEditor;
}

class FacilityEditor : public QWidget
{
    Q_OBJECT

public:
    explicit FacilityEditor(QWidget *parent = 0);
    ~FacilityEditor();

private:
    Ui::FacilityEditor *ui;
};

#endif // FACILITYEDITOR_H
