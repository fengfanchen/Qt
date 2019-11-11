#ifndef SQL_H
#define SQL_H

#include <QSqlDatabase>


class SQL
{
public:
    SQL();
    QVector<QStringList> limitSql(const int &start = 0, const int &num = 0);
    int getCount();

private:
    QSqlDatabase m_db;
};

#endif // SQL_H
