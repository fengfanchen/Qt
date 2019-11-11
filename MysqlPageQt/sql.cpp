#include "sql.h"
#include <QDebug>
#include <QSqlRecord>
#include <QVector>
#include <QSqlQuery>
#include <QSqlError>

SQL::SQL()
{

    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("192.1.101.177");
    m_db.setPort(3306);
    m_db.setUserName("root");
    m_db.setPassword("root");
    m_db.setDatabaseName("testdb");

    if(!m_db.open()){

        qDebug() << "m_db open failed " << m_db.lastError().text();
        return;
    }
}

QVector<QStringList> SQL::limitSql(const int &start, const int &num)
{
    QVector<QStringList> listVec;
    QString cmd = QString("SELECT id, value1, value2 FROM test LIMIT %1,%2").arg(start).arg(num);
    QSqlQuery sqlQuery;
    QStringList headList;


    if(!sqlQuery.exec(cmd))
        return listVec;


    //获得头
    QSqlRecord sqlRecord(sqlQuery.record());

    for(int i = 0; i < sqlRecord.count(); i++){

        headList << sqlRecord.fieldName(i);
    }

    listVec.append(headList);


    while(sqlQuery.next()){

        QStringList strList;
        for(int i = 0; i < headList.size(); i++){

            strList << sqlQuery.value(headList[i]).toString();
        }
        listVec.append(strList);

    }


    return listVec;

}

int SQL::getCount()
{
    QString cmd = QString("SELECT count(*) FROM test");
    QSqlQuery sqlQuery;
    QStringList headList;


    if(!sqlQuery.exec(cmd))
        return -1;

    QSqlRecord sqlRecord(sqlQuery.record());

    for(int i = 0; i < sqlRecord.count(); i++){

        headList << sqlRecord.fieldName(i);
    }

    while(sqlQuery.next()){

        for(int i = 0; i < headList.size(); i++){

            return sqlQuery.value(headList[i]).toInt();
        }

    }
    return -1;
}
