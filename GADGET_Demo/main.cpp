#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaMethod>
#include <QMetaEnum>
#include <QMetaObject>
#include "GadgetTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int count = GadgetTest::staticMetaObject.enumeratorCount();
    for(int i = 0; i < count; i++){

        QMetaEnum en = GadgetTest::staticMetaObject.enumerator(i);
        int enCount = en.keyCount();
        for(int j = 0; j < enCount; j++){

            qDebug() << en.value(j);
            qDebug() << en.key(j);
        }
        qDebug() << "----------------华丽的分割线----------------";
    }

    return a.exec();
}
