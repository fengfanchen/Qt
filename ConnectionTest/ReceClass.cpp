#include "ReceClass.h"
#include <QDebug>
#include <QThread>

ReceClass::ReceClass(QObject *parent) : QObject(parent)
{

}

void ReceClass::receMsg(QString msg)
{
    qDebug() << "Get msg: " +  msg;
    QThread::sleep(1);
}
