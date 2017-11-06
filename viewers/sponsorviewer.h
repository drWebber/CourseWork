#ifndef SPONSORVIEWER_H
#define SPONSORVIEWER_H

#include <QWidget>
#include <qsqlquerymodel.h>

namespace Ui {
class SponsorViewer;
}

class SponsorViewer : public QWidget
{
    Q_OBJECT

public:
    explicit SponsorViewer(QWidget *parent = 0);
    ~SponsorViewer();
    enum COLUMNS {SPONSOR, COMPETITION_NUM};
private slots:
    void onFilterChanged();
    void onDataRangeEnabled(bool status);
private:
    Ui::SponsorViewer *ui;
    QSqlQueryModel *model;
};

#endif // SPONSORVIEWER_H
