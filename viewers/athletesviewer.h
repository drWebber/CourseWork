#ifndef ATHLETESVIEWER_H
#define ATHLETESVIEWER_H

#include <QWidget>
#include "viewers/abstractviewer.h"

namespace Ui {
class AthletesViewer;
}

class AthletesViewer : public QWidget, AbstractViewer
{
    Q_OBJECT

public:
    explicit AthletesViewer(QWidget *parent = 0);
    ~AthletesViewer();

private:
    Ui::AthletesViewer *ui;
};

#endif // ATHLETESVIEWER_H
