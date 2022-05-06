#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QDebug>

class TestClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int intValue READ getIntValue WRITE setIntValue)
    Q_PROPERTY(float floatValue READ getFloatValue WRITE setFloatValue)
    Q_PROPERTY(QString qstringValue READ getQStringValue WRITE setQStringValue)
    Q_PROPERTY(qlonglong qlonglongValue READ getQlonglongValue WRITE setQlonglongValue)
    Q_PROPERTY(QList<QVariant> qListValue READ getQListValue WRITE setQListValue)

public:
    Q_INVOKABLE TestClass(){}
    ~TestClass(){ qDebug() << "~TestClass() called"; }

    friend QDebug operator << (QDebug os, TestClass &testClass){

        os << "[";
        os << "(" << "intValue: " << testClass.getIntValue() << ", " <<
              "floatValue: " << testClass.getFloatValue() << ", " <<
              "QStringValue: " << testClass.getQStringValue() << ", " <<
              "qlonglongValue: " << testClass.getQlonglongValue() << ")";
        for(const QVariant &item : testClass.getQListValue()){

            os << "list: " << item;
        }
        os << "]";

        return os;
    }

    int getIntValue(){

        return this->intValue;
    }

    float getFloatValue(){

        return this->floatValue;
    }

    QString getQStringValue(){

        return this->qstringValue;
    }

    qlonglong getQlonglongValue(){

        return this->qlonglongValue;
    }

    QList<QVariant> getQListValue(){

        return this->qListValue;
    }

    void setIntValue(int value){

        this->intValue = value;
    }

    void setFloatValue(float value){

        this->floatValue = value;
    }

    void setQStringValue(QString value){

        this->qstringValue = value;
    }

    void setQlonglongValue(qlonglong value){

        this->qlonglongValue = value;
    }

    void setQListValue(QList<QVariant> value){

        qListValue.clear();
        for(const QVariant &item : value){

            this->qListValue.append(item);
        }
    }

private:
    int intValue;
    float floatValue;
    QString qstringValue;
    qlonglong qlonglongValue;
    QList<QVariant> qListValue;

};

#endif // TESTCLASS_H
