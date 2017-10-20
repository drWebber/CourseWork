#ifndef ATHLETEVIEWER_H
#define ATHLETEVIEWER_H

#include <QWidget>
#include "abstracttableview.h"

namespace Ui {
class AthleteViewer;
}

class AthleteViewer : public AbstractTableView
{
    Q_OBJECT

public:
    explicit AthleteViewer(QWidget *parent = 0);
    ~AthleteViewer();
private:
    Ui::AthleteViewer *ui;
};

#endif // ATHLETEVIEWER_H
