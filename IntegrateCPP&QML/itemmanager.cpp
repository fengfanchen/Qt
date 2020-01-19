#include "itemmanager.h"
#include "backend.h"
#include <QDebug>

ItemManager *ItemManager::m_instance = nullptr;

ItemManager::ItemManager(QObject *parent) : QObject(parent)
{

}

ItemManager::ItemManager()
{

}

ItemManager::ItemManager(ItemManager &item)
{
    Q_UNUSED(item)
}

void ItemManager::addItem(QObject *item)
{
    if(m_instance == nullptr){

        qDebug() << "m_instance is nullptr";
        return;
    }

    m_item << item;
}

QObject *ItemManager::getObject()
{
    if(m_instance == nullptr){

        qDebug() << "m_instance is nullptr";
        Q_NULLPTR;
    }

    return m_item.at(0);
}

void ItemManager::printTest()
{
    if(m_instance == nullptr){

        qDebug() << "m_instance is nullptr";
        return;
    }

    //这里简单一点，就打印一个
    BackEnd *backEnd = qobject_cast<BackEnd*>(m_item.at(0));
    qDebug() << backEnd->userName();
}

ItemManager::~ItemManager()
{
    qDebug() << "ItemManager::~ItemManager() called";
    for(int i = 0; i < m_item.size(); i++){

        delete m_item.at(i);
    }
}

ItemManager *ItemManager::getInstance()
{
    if(m_instance == nullptr){

        m_instance = new ItemManager(nullptr);
        return m_instance;
    }

    return m_instance;
}
