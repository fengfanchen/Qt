#include "MySQLInstance.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMutex>
#include <QVariant>

MySQLInstance *MySQLInstance::m_instance = nullptr;
QMutex mt;

MySQLInstance *MySQLInstance::getInstance()
{
    if(m_instance == nullptr){

        mt.lock();
        if(m_instance == nullptr){

            m_instance = new MySQLInstance();
            mt.unlock();
            return m_instance;
        }
        mt.unlock();
    }

    return m_instance;
}

QString MySQLInstance::execSql(const QString &cmd)
{
    if(m_instance == nullptr){

        Q_ASSERT(!"m_instance == nullptr");
    }


    //简单点，返回值只有一个
    mt.lock();
    QSqlQuery query(m_db);
    if(!query.exec(cmd)){

        mt.unlock();
        qDebug() << "error:" << query.lastError().text();
        return "error";
    }
    mt.unlock();

    QString ret = "none";
    while(query.next()){

        ret = query.value(0).toString();
    }


    return ret;
}

MySQLInstance::MySQLInstance()
{
    connectMySQL();
}

void MySQLInstance::connectMySQL()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("127.0.0.1");
    m_db.setPort(3306);
    m_db.setDatabaseName("mysql");
    m_db.setUserName("root");
    m_db.setPassword("root");
    m_db.open();
}
