#include "ReflectTest.h"

ReflectTest::ReflectTest(QObject *parent) : QObject(parent)
{

}

void ReflectTest::setPrint(const QString &print)
{
    m_print = print;
}

QString ReflectTest::getPrint()
{
    return m_print;
}

QString ReflectTest::testFunction(QString para)
{
    return "return:" + para;
}
