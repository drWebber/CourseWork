#include "sequenselist.h"
#include <qdebug.h>

SequenseList::SequenseList()
{

}

void SequenseList::append(const QStringList sequence)
{
    lenList.append(sequence.length());
    sq.append(sequence);
}

void SequenseList::clear()
{
    sq.clear();
    lenList.clear();
}

QStringList SequenseList::getIntersectionList()
{
    QStringList result;
    if (!sq.isEmpty()) {
        int lSqIndex = getLargestSeqIndex();
        QStringList largestList = sq.at(lSqIndex);
        for (int i = 0; i < largestList.count(); ++i) {
            QString current = largestList.at(i);
            if (isIntersection(current))
                if (!result.contains(current))
                    result.append(current);
        }
    }
    return result;
}

int SequenseList::getLargestSeqIndex()
{
    int index = 0;
    if (lenList.length() > 0) {
        int max = 0;
        for (int i = 0; i < lenList.count(); ++i) {
            if (lenList.at(i) > max) {
                index = i;
                max = lenList.at(i);
            }
        }
    }
    return index;
}

int SequenseList::count()
{
    return sq.length();
}

bool SequenseList::isIntersection(QString value)
{
    bool isIntersection = true;
    for (int j = 0; j < sq.count(); ++j) {
        if (!sq.at(j).contains(value))
            isIntersection = false;
    }
    return isIntersection;
}
