#include <QCoreApplication>
#include <QLibrary>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLibrary myLib("D:\\QtProject\\libraryDemo\\DLL_C_Demo");
    typedef int (*Add)(int a, int b);
    Add function = (Add)myLib.resolve("Add");
    if(function){

        qDebug() << function(10, 20);
    }

    qDebug() << "----------华丽的分割线----------";

    typedef int (*Sub)(int a, int b);
    Sub function2 = (Sub)QLibrary::resolve("D:\\QtProject\\libraryDemo\\DLL_C_Demo.dll", "Sub");
    if(function2){

        qDebug() << function2(10, 100);
    }

    return a.exec();
}
