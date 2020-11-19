#include <QCoreApplication>
#include <QMetaEnum>
#include <QDebug>
#include "EnumTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMetaEnum myType = QMetaEnum::fromType<EnumTest::MyType>();
    int count = myType.keyCount();

    for(int i = 0; i < count; i++){

        qDebug() << myType.value(i);
    }

    qDebug() << "----------华丽的分割线----------";

    qDebug() << EnumTest::MyType::One;
    qDebug() << EnumTest::One1;

    qDebug() << "----------华丽的分割线----------";
    QVariant var;
    qDebug() << var.value<EnumTest::MyType>();
    qDebug() << var.value<EnumTest::CType>();

    if(EnumTest::MyType::One == 0){

        qDebug() << "zero";
    }

    return a.exec();
}
