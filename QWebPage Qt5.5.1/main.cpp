#include "thumbnailer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Thumbnailer w(QUrl("http://www.baidu.com"));
    Q_UNUSED(w)
    return a.exec();
}
