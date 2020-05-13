#include "WorkerThread.h"
#include "ProjectData.h"
#include <QPointer>
#include <QTime>

WorkerThread::WorkerThread()
{
    stopFlag = false;
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
}

void WorkerThread::setProjectData(ProjectData *project)
{
    m_project = project;
}

void WorkerThread::run()
{
    while(true){

        if(stopFlag){

            QThread::sleep(1);
            break;
        }

        QPointer<QObject> ptr = m_project->getItem();
        if(!ptr){

            QThread::sleep(1);
            continue;
        }

        //开始处理数据
        int disposeTime = qrand() % 5;
        qDebug() << "线程:" << QThread::currentThread() << "处理" << ptr << " 需要" << disposeTime << "S";
        QThread::sleep(disposeTime);
        delete ptr;
        //qDebug() << "ptr" << ptr;
    }
}
