#ifndef CONCURRENT_H
#define CONCURRENT_H

#include <QObject>
#include <QList>


class BigDataTest : public QObject
{
    Q_OBJECT
public:
    BigDataTest(QObject *parent = 0);
    void run();

protected:
    bool connectMySQL();
    friend QString sqlResult(const QString &cmd);

private:
    QList<QString> m_str;
};

#endif // CONCURRENT_H
