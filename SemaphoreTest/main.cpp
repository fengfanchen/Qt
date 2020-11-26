#include <QCoreApplication>
#include <QSemaphore>
#include <QThread>
#include <QDebug>
#include "Worker.h"
#include "Boss.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSemaphore sem(-2);

    qDebug() <<"主线程[" << QThread::currentThread() << "]: 开始运行";

    QThread thread1;
    QThread thread2;
    QThread thread3;
    QThread thread4;
    Worker worker1(&sem, "张三");
    Worker worker2(&sem, "李四");
    Worker worker3(&sem, "王二");
    Boss boss(&sem);
    worker1.moveToThread(&thread1);
    worker2.moveToThread(&thread2);
    worker3.moveToThread(&thread3);
    boss.moveToThread(&thread4);

    QObject::connect(&thread1, &QThread::started, &worker1, &Worker::doWork);
    QObject::connect(&thread1, &QThread::finished, &worker1, &QObject::deleteLater);

    QObject::connect(&thread2, &QThread::started, &worker2, &Worker::doWork);
    QObject::connect(&thread2, &QThread::finished, &worker2, &QObject::deleteLater);

    QObject::connect(&thread3, &QThread::started, &worker3, &Worker::doWork);
    QObject::connect(&thread3, &QThread::finished, &worker3, &QObject::deleteLater);

    QObject::connect(&thread4, &QThread::started, &boss, &Boss::doWork);
    QObject::connect(&thread4, &QThread::finished, &boss, &QObject::deleteLater);

    thread1.start();
    QThread::sleep(1);  //为了产生不同的随机种子
    thread2.start();
    QThread::sleep(1);  //为了产生不同的随机种子
    thread3.start();
    thread4.start();

    return a.exec();
}
