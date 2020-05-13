#include <QCoreApplication>
#include <QTimer>
#include <QObject>
#include <QEventLoop>
#include "WorkerThread.h"
#include "ProjectData.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ProjectData *p = new ProjectData;


    //设置消费者线程
    WorkerThread *p1 = new WorkerThread;
    WorkerThread *p2 = new WorkerThread;
    WorkerThread *p3 = new WorkerThread;
    WorkerThread *p4 = new WorkerThread;
    WorkerThread *p5 = new WorkerThread;

    p1->setProjectData(p);
    p2->setProjectData(p);
    p3->setProjectData(p);
    p4->setProjectData(p);
    p5->setProjectData(p);

    p1->start();
    p2->start();
    p3->start();
    p4->start();
    p5->start();

    //设置生产者生产者
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [=](){

        QObject *test = new QObject;
        test->setObjectName("新数据ABC");
        p->addItem(test);
        qDebug() << "当前剩余资源:" << p->getSize();
    });

    timer.start(300);

    QTimer::singleShot(1000 * 20, [=]{

        p1->stopFlag = true;
        p2->stopFlag = true;
        p3->stopFlag = true;
        p4->stopFlag = true;
        p5->stopFlag = true;

        QEventLoop loop;
        QTimer::singleShot(1000 * 5, &loop, SLOT(quit()));
        loop.exec();

        delete p;
        qDebug() << "退出";
        qApp->quit();
    });


    return a.exec();
}
