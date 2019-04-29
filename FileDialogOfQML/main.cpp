#include <QApplication>
#include <QUrl>
#include <QQuickWindow>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QQuickWindow::setDefaultAlphaBuffer(true);
    QQmlApplicationEngine engine(QUrl("qrc:/main.qml"));

    return a.exec();
}
