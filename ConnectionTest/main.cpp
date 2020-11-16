#include <QCoreApplication>
#include "Demo1.h"
#include "ReceClass.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //init
    ReceClass receClass;
    Demo1 demo1;
    Demo1 demo2;


    //bind
//    QObject::connect(&demo1, &Demo1::sendMsg, &receClass, &ReceClass::receMsg, Qt::QueuedConnection);
//    QObject::connect(&demo2, &Demo1::sendMsg, &receClass, &ReceClass::receMsg, Qt::QueuedConnection);

//    QObject::connect(&demo1, &Demo1::sendMsg, &receClass, &ReceClass::receMsg, Qt::DirectConnection);
//    QObject::connect(&demo2, &Demo1::sendMsg, &receClass, &ReceClass::receMsg, Qt::DirectConnection);


    qDebug() << QObject::connect(&demo1, &Demo1::sendMsg, &receClass, &ReceClass::receMsg, static_cast<Qt::ConnectionType>(Qt::QueuedConnection | Qt::UniqueConnection));
    qDebug() << QObject::connect(&demo2, &Demo1::sendMsg, &receClass, &ReceClass::receMsg, static_cast<Qt::ConnectionType>(Qt::QueuedConnection | Qt::UniqueConnection));
    qDebug() << QObject::connect(&demo1, &Demo1::sendMsg, &receClass, &ReceClass::receMsg, static_cast<Qt::ConnectionType>(Qt::DirectConnection | Qt::UniqueConnection));
    qDebug() << QObject::connect(&demo2, &Demo1::sendMsg, &receClass, &ReceClass::receMsg, static_cast<Qt::ConnectionType>(Qt::DirectConnection | Qt::UniqueConnection));

    //run
    demo1.setMsg("demo1");
    demo2.setMsg("demo2");


    demo1.start();
    demo2.start();


    return a.exec();
}
