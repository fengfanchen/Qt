#include <QApplication>
#include <QSettings>
#include "httpserver/httplistener.h"
#include "myrequesthandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSettings *listenerSettings=new QSettings("E:\\Qt2019\\useQtWebAPP\\conf.ini", QSettings::IniFormat, &a);
    listenerSettings->beginGroup("listener");

    new HttpListener(listenerSettings, new MyRequestHandler, &a);

    return a.exec();
}
