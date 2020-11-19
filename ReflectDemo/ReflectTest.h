#ifndef REFLECTTEST_H
#define REFLECTTEST_H

#include <QObject>

class ReflectTest : public QObject
{
    Q_OBJECT
public:
    ReflectTest(QObject *parent = nullptr);
    Q_INVOKABLE void setPrint(const QString &print);
    Q_INVOKABLE QString getPrint();
    Q_INVOKABLE QString testFunction(QString para);

private:
    QString m_print;

};

#endif // REFLECTTEST_H
