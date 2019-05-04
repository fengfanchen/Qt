#ifndef MYREQUESTHANDLER_H
#define MYREQUESTHANDLER_H

#include "httpserver/httprequesthandler.h"
using namespace stefanfrings;

class MyRequestHandler: public HttpRequestHandler
{
    Q_OBJECT
public:
    MyRequestHandler(QObject* parent=nullptr);
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // MYREQUESTHANDLER_H
