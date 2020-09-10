#include "BigDataTest.h"
#include "MySQLInstance.h"
#include <QDebug>
#include <QtConcurrent>
#include <QSqlQuery>

BigDataTest::BigDataTest(QObject *parent) : QObject(parent)
{

    m_str << "SELECT 1 + 1" << "SELECT 100 * 100 * 100 / 10" << "SELECT 100 + 99" << "SELECT 1 + 1"
          << "SELECT 1 + 1 + 500" << "SELECT 1 + 1 + 1000" << "SELECT 1999 - 199" << "SELECT 1999 + 10"
          << "SELECT 1 + 1 + 8888" << "SELECT 1 + 1 + 788";
}

QString sqlResult(const QString &cmd)
{
    qDebug() << "处理SQL语句进程 : " << QThread::currentThread();
    MySQLInstance *instance = MySQLInstance::getInstance();
    return instance->execSql(cmd);
}


void BigDataTest::run()
{
    QList<QString> retList = QtConcurrent::blockingMapped(m_str, sqlResult);
    qDebug() << "返回结果";
    qDebug() << retList;
}
