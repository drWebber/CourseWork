#ifndef TESTMAPPER_H
#define TESTMAPPER_H

#include <QWidget>
#include <qdatawidgetmapper.h>
#include <qsqlrelationaltablemodel.h>

namespace Ui {
class TestMapper;
}

class TestMapper : public QWidget
{
    Q_OBJECT

public:
    explicit TestMapper(QWidget *parent = 0);
    ~TestMapper();
    void setModel(QSqlRelationalTableModel *model, const QModelIndex &index);
private:
    Ui::TestMapper *ui;
    QDataWidgetMapper *mapper;
};

#endif // TESTMAPPER_H
