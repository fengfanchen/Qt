#include "Worker.h"
#include <QSemaphore>
#include <QThread>
#include <QTime>
#include <QDebug>

Worker::Worker(QSemaphore *sem, QString name, QObject *parent) : QObject(parent)
{
    m_sem = sem;
    m_name = name;
}

Worker::~Worker()
{
    qDebug() << m_name << " 析构";
}

void Worker::doWork()
{
    qsrand(QTime::currentTime().msec() + QTime::currentTime().second()*1000);
    qDebug() << "子线程[" << QThread::currentThread() << "]: " << m_name << " 正在干活...";
    QThread::sleep(qrand() % 10 + 5);
    qDebug() << "子线程[" << QThread::currentThread() << "]: " << m_name << " 活干完了！！！";
    m_sem->release(1);
}
