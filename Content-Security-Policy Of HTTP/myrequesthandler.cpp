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

    //例子 1
    //    response.setHeader("Content-Security-Policy", "default-src http: https:");
    //    response.write("<h1>CSDN IT1995</h1>");
    //    response.write("<script>console.log(\"inline js\")</script>");


    //例子 2
    //    if(str.contains("js")){

    //        response.setHeader("Content-Type", "application/javascript");
    //        response.write("console.log(\"IT1995\")");
    //    }
    //    else{

    //        response.setHeader("Content-Type", "text/html");
    //        response.setHeader("Content-Security-Policy", "default-src 'self'");

    //        response.write("<h1>CSDN IT1995</h1>");
    //        response.write("<script src=\"/test.js\"></script>");
    //    }

    //例子 3
//    if(str.contains("js")){

//        response.setHeader("Content-Type", "application/javascript");
//        response.write("console.log(\"IT1995\")");
//    }
//    else{

//        response.setHeader("Content-Type", "text/html");
//        response.setHeader("Content-Security-Policy", "default-src 'self' https://cdn.bootcss.com/");

//        response.write("<h1>CSDN IT1995</h1>");
//        response.write("<script src=\"/test.js\"></script>");
//        response.write("<script src=\"https://cdn.bootcss.com/react/16.9.0-alpha.0/cjs/react.development.js\"></script>");

//    }

    //例子 4
    response.setHeader("Content-Type", "text/html");
    response.setHeader("Content-Security-Policy", "script-src 'self'; form-action 'self'");

    response.write("<h1>CSDN IT1995</h1>");
    response.write("<form action=\"https://www.baidu.com\">"
                   "<button type=\"submit\">clicke me</button>"
                   "</form>");
}
