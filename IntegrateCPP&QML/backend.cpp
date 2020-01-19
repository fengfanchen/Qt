#include "backend.h"
#include "itemmanager.h"
#include <QDebug>

BackEnd::BackEnd(QObject *parent) : QObject(parent)
{

    ItemManager *manager = ItemManager::getInstance();
    manager->addItem(this);

    connect(this, &BackEnd::userNameChanged, [=] (){

        qDebug() << m_userName;
    });
}

BackEnd::~BackEnd()
{
    qDebug() << "BackEnd::~BackEnd() called";
}

QString BackEnd::userName(){

    return m_userName;
}

void BackEnd::setUserName(const QString &userName){

    if(userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}
