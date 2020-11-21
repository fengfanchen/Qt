#ifndef GADGETTEST_H
#define GADGETTEST_H

#include <QObject>

class GadgetTest
{
    Q_GADGET
public:
    GadgetTest();
    enum Priority { High, Low, VeryHigh, VeryLow };
    enum Type{Zero, One, Two, Three};
    Q_ENUM(Priority)
    Q_ENUM(Type)
};

#endif // GADGETTEST_H
