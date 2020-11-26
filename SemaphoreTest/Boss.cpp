#include "Boss.h"
#include <QThread>
#include <QDebug>
#include <QSemaphore>

Boss::Boss(QSemaphore *sem, QObject *parent) : QObject(parent)
{
    m_sem = sem;
}

Boss::~Boss()
{
    qDebug() << "BOSS 析构";
}

void Boss::doWork()
{
    qDebug() << "子线程[" << QThread::currentThread() << "]: " << "BOSS" << " 等待所有人完成工作...";
    m_sem->acquire(1);
    qDebug() << "子线程[" << QThread::currentThread() << "]: " << "BOSS" << " 开始检测工作！！！";
}
