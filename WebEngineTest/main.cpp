#include "Widget.h"
#include <QApplication>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();

    QWebEngineView view;
    view.load(QUrl("http://192.1.101.118:8888"));
    view.show();

    return a.exec();
}
