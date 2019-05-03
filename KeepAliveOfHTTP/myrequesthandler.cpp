#include "myrequesthandler.h"
#include <QByteArray>
#include <QImage>
#include <QDebug>

MyRequestHandler::MyRequestHandler(QObject* parent): HttpRequestHandler(parent)
{
    Q_UNUSED(parent)
}

void MyRequestHandler::service(HttpRequest &request, HttpResponse &response)
{
    QByteArray path=request.getPath();
    QString str(path);

    if(str == "/"){

        response.setHeader("Content-Type", "text/html");
        QFile file(":/re/index.html");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){

            qDebug() << "opening file error";
            return;
        }

        response.write(file.readAll());
    }
    else{

        QImage *image = new QImage(":/re/pic.jpg");
        response.setHeader("content-Type", "image/jpg");
        QByteArray array((char*)image->bits(), image->byteCount());
        response.write(array);
    }
}
