#include <QApplication>
#include <QQmlApplicationEngine>
#include <QPushButton>
#include "backend.h"
#include "itemmanager.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    qmlRegisterType<BackEnd>("cn.it1995.bakend", 1, 0, "BackEnd");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    ItemManager *manager = ItemManager::getInstance();

    QPushButton pushButton1;
    pushButton1.setText("获取QML中的值");
    QObject::connect(&pushButton1, &QPushButton::clicked, [=](){

        manager->printTest();
    });
    pushButton1.show();

    QPushButton pushButton2;
    pushButton2.setText("设置QML中的值");
    QObject::connect(&pushButton2, &QPushButton::clicked, [=]() mutable{

        BackEnd *backEnd = qobject_cast<BackEnd*>(manager->getObject());
        backEnd->setUserName("Hello 中文");
    });
    pushButton2.show();

    return app.exec();
}
