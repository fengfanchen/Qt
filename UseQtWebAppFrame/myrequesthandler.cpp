#include "myrequesthandler.h"
#include <QByteArray>
#include <QDebug>

MyRequestHandler::MyRequestHandler(QObject* parent): HttpRequestHandler(parent)
{
    Q_UNUSED(parent)
}

void MyRequestHandler::service(HttpRequest &request, HttpResponse &response)
{
    QByteArray path=request.getPath();
    qDebug() << path;

    QByteArray username("IT1995");

    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");

    response.write("<html><body>");
    response.write("<h1>");
    response.write("Hello ");
    response.write(username);
    response.write("</h1>");
    response.write("</body></html>");
}
