#include <QCoreApplication>
#include <QxOrm_Impl.h>
#include <QDebug>
#include "precompiled.h"
#include "user.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile::remove("D:\\QtProject\\build-qxDemo1-Desktop_Qt_5_14_0_MinGW_32_bit-Debug\\qxDemo1.sqlite");

    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("D:\\QtProject\\build-qxDemo1-Desktop_Qt_5_14_0_MinGW_32_bit-Debug\\qxDemo1.sqlite");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("root");
    qx::QxSqlDatabase::getSingleton()->setPassword("");
    qx::QxSqlDatabase::getSingleton()->setFormatSqlQueryBeforeLogging(true);
    qx::QxSqlDatabase::getSingleton()->setDisplayTimerDetails(true);

    qx::QxSqlDatabase::getSingleton()->setVerifyOffsetRelation(true);

    //更具上面类型创建表
    QSqlError daoError = qx::dao::create_table<User>();

    User_ptr user_1, user_2;
    user_1.reset(new User);
    user_2.reset(new User);

    user_1->id = 1;
    user_1->name = "猪小明";
    user_1->age = 18;
    user_1->capacity = 99.9;

    user_2->id = 2;
    user_2->name = "球球";
    user_2->age = 18;
    user_2->capacity = 99999.9;

    QSqlDatabase db = qx::QxSqlDatabase::getDatabase();
    bool bCommit = db.transaction();

    //猪小明入库
    daoError = qx::dao::insert(user_1, &db);
    bCommit = (bCommit && ! daoError.isValid());
    qAssert(bCommit);
    db.commit();

    //球球入库
    daoError = qx::dao::save(user_2);
    bCommit = !daoError.isValid();
    qAssert(bCommit);

    //通过SQL进行检索，映射到 typedef qx::QxCollection<int, User_ptr> List_user;中
    List_user list_user;
    qx_query storedProc("select * from user");
    daoError = qx::dao::execute_query(storedProc, list_user);

    List_user::iterator it = list_user.begin();

    qDebug() << "------------------华丽的分割线------------------";
    while(it != list_user.end()){

        qDebug() << "id:" << it.i->t().second->id;
        qDebug() << "name:" << it.i->t().second->name;
        qDebug() << "age:" << it.i->t().second->age;
        qDebug() << "capacity:" << it.i->t().second->capacity;
        it++;
    }
    qDebug() << "------------------华丽的分割线------------------";

    //修改下
    it = list_user.begin();
    while(it != list_user.end()){

        it.i->t().second->capacity = 59.9;
        it++;
    }

    qx::dao::update(list_user);


    //新增及删除
    User_ptr user_3;
    user_3.reset(new User);

    user_3->id = 100;
    user_3->name = "闰土";
    user_3->age = 19;
    user_3->capacity = 99999.9999;
    list_user.removeByKey(2);
    list_user.insert(100, user_3);

    qx::dao::save(user_3);
    qx::dao::delete_by_id<User>(*user_2);

    return a.exec();
}
