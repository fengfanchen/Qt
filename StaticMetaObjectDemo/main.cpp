#include "TestClass.h"
#include <QMetaObject>
#include <QMetaProperty>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    const QMetaObject *metaObject = &TestClass::staticMetaObject;
    QObject *obj = metaObject->newInstance();

    //获取属性
    QStringList propertyList;

    for(int i = metaObject->propertyOffset(); i < metaObject->propertyCount(); i++){

        propertyList << metaObject->property(i).name();
    }

    //通过反射设置值
    for(const QString &property : propertyList){

        if(property == "intValue"){

            obj->setProperty(property.toUtf8(), 10);
        }
        else if(property == "floatValue"){

            obj->setProperty(property.toUtf8(), 10.1f);
        }
        else if(property == "qstringValue"){

            obj->setProperty(property.toUtf8(), "HelloWorld");
        }
        else if(property == "qlonglongValue"){

            obj->setProperty(property.toUtf8(), 9999999999999);
        }
        else if(property == "qListValue"){

            QList<QVariant> list;
            list << "10086" << "10010" << "10000";
            obj->setProperty(property.toUtf8(), list);
        }
    }

    qDebug() << (*(TestClass*)obj);

    delete obj;

    return 0;
}
