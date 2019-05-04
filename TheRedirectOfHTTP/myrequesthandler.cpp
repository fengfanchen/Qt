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

        response.setStatus(302);
        response.setHeader("Location", "/new");
    }
    else{

        response.setStatus(200);
        response.setHeader("Content-Type", "text/html");
        response.write("<h1>IT1995</h1>");
    }
}
