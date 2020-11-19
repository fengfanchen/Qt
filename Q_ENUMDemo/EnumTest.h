#ifndef ENUMTEST_H
#define ENUMTEST_H

#include <QObject>

class EnumTest : public QObject
{
    Q_OBJECT
public:
    EnumTest(QObject *parent = nullptr);
    enum MyType{
        One, Two, Three, Four
    };
    enum CType{
        One1, Two2, Three3, Four4
    };

    Q_ENUM(MyType)

};

#endif // ENUMTEST_H
