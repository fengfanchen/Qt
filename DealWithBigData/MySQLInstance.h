#ifndef MYSQLINSTANCE_H
#define MYSQLINSTANCE_H

#include <QSqlDatabase>

class MySQLInstance
{
public:
    static MySQLInstance *getInstance();
    QString execSql(const QString &cmd);

protected:
    MySQLInstance();
    void connectMySQL();

private:
    static MySQLInstance *m_instance;
    QSqlDatabase m_db;
};

#endif // MYSQLINSTANCE_H
