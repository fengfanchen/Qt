#include "Woork.h"
#include <QDateTime>
#include <QDebug>

Work::Work()
{
    qDebug() << "Work::Work()";
}

Work::~Work()
{
    qDebug() << "Work::~Work()";
}

void Work::run()
{
    emit this->nowTime(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
}
