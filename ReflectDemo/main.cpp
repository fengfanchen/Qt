#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaMethod>
#include "ReflectTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ReflectTest test1;
    test1.setPrint("one");
    qDebug() << test1.getPrint();
    qDebug() << "----------华丽的分割线----------";
    int count = test1.metaObject()->methodCount();
    for(int i = 0; i < count; i++){

        qDebug() << test1.metaObject()->method(i).name();
    }

    qDebug() << "----------华丽的分割线----------";

    qDebug() << test1.getPrint();
    qDebug() << QMetaObject::invokeMethod(&test1, "setPrint", Qt::DirectConnection, Q_ARG(QString, "one+one"));
    QString retVal;
    QMetaObject::invokeMethod(&test1, "getPrint", Qt::DirectConnection, Q_RETURN_ARG(QString, retVal));
    qDebug() << retVal;

    QMetaObject::invokeMethod(&test1, "testFunction", Qt::DirectConnection, Q_RETURN_ARG(QString, retVal), Q_ARG(QString, "one+one+one"));
    qDebug() << retVal;

    return a.exec();
}
