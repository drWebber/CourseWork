#ifndef SEQUENSELIST_H
#define SEQUENSELIST_H

#include <qlist.h>



class SequenseList
{
public:
    SequenseList();
    void append(const QStringList sequence);
    void clear();
    QStringList getIntersectionList();
    int getLargestSeqIndex();
    int count();
private:
    QList<QStringList> sq;
    QList<int> lenList;
    bool isIntersection(QString value);
};

#endif // SEQUENSELIST_H
