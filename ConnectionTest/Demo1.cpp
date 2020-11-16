#include "Demo1.h"
#include <QDebug>


void Demo1::run()
{
    for(int i = 0; i < 10; i++){

        emit sendMsg(this->m_msg);
        qDebug() << "emit " << this->m_msg << " over";
    }
    qDebug() << "msg:" << this->m_msg << " over";
}

void Demo1::setMsg(const QString &msg)
{
    this->m_msg = msg;
}
