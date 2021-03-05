#include "Com.h"
#include "Woork.h"
#include <QTimer>
#include <QThreadPool>
#include <QDebug>

Com::Com(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    m_pool = new QThreadPool(this);
    m_pool->setMaxThreadCount(1);

    connect(m_timer, &QTimer::timeout, this, &Com::timeOut);
    m_timer->start(1000);
}

void Com::timeOut()
{
    Work *work = new Work;
    connect(work, &Work::nowTime, this, &Com::getTime);
    m_pool->start(work);
}

void Com::getTime(const QString &time)
{
    qDebug() << "接收到:" + time;
}
