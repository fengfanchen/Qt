#include "ProjectData.h"
#include <QMutex>

QMutex mutex;

ProjectData::ProjectData(QObject *parent) : QObject(parent)
{

}


void ProjectData::addItem(QObject *item)
{
    m_objList.append(item);
}

int ProjectData::getSize()
{
    return m_objList.size();
}

QObject* ProjectData::getItem()
{
    mutex.lock();
    if(m_objList.size() == 0){

        mutex.unlock();
        return nullptr;
    }

    QObject *ret = m_objList[0];
    m_objList.removeFirst();
    mutex.unlock();
    return ret;
}

QList<QObject *> ProjectData::getAll()
{
    return m_objList;
}
