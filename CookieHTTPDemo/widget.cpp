#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_tcpServer = new QTcpServer(this);
    m_tcpServer->listen(QHostAddress::Any, 80);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(btnClicked()));
    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(newConnectionSlot()));
    connect(m_tcpServer, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(errorStringSlot()));
}

Widget::~Widget()
{
    delete ui;
     m_tcpServer->close();
}

void Widget::newConnectionSlot()
{
    qDebug() << "newConnectionSlot80() called";
    m_tcpSocket = m_tcpServer->nextPendingConnection();
    sendMsg();
}

void Widget::errorStringSlot()
{
    qDebug() << m_tcpServer->errorString();
}

int choose = 0;

void Widget::btnClicked()
{
    if(choose == 0){

        ui->pushButton->setText("无Cookie");
        choose++;
    }
    else if(choose == 1){

        ui->pushButton->setText("domin相关");
        choose++;
    }
    else{

        ui->pushButton->setText("有max-age");
        choose = 0;
    }
}

void Widget::sendMsg()
{
    QString contentStr;
    QString str;
    contentStr = "<html>"
                 "<head>"
                 "<title>"
                 "Socket 80"
                 "</title>"
                 "</head>"
                 "<body>"
                 "<h1>Socket 80</h1>"
                 "</body>"
                 "<script>"
                 "  console.log(document.cookie)"
                 "</script>"
                 "</html>";

    if(ui->pushButton->text() == "有max-age"){
        
        str = "HTTP/1.1 200 OK\r\n";
        str.append("Server:nginx\r\n");
        str.append("Content-Type:text/html\r\n");
        str.append("Access-Control-Allow-Origin: *\r\n");
        str.append("Set-Cookie: id=123456; max-age=10\r\n");
        str.append("Set-Cookie: name=123456\r\n");
        str.append(QString("Content-Length:%1\r\n\r\n").arg(contentStr.size()));
        str.append(contentStr);
    }
    else if(ui->pushButton->text() == "无Cookie"){

        str = "HTTP/1.1 200 OK\r\n";
        str.append("Server:nginx\r\n");
        str.append("Content-Type:text/html\r\n");
        str.append("Access-Control-Allow-Origin: *\r\n");
        str.append(QString("Content-Length:%1\r\n\r\n").arg(contentStr.size()));
        str.append(contentStr);
    }
    else{

        str = "HTTP/1.1 200 OK\r\n";
        str.append("Server:nginx\r\n");
        str.append("Content-Type:text/html\r\n");
        str.append("Access-Control-Allow-Origin: *\r\n");
        str.append("Set-Cookie: id=123456;domain=it1995.cn\r\n");
        str.append("Set-Cookie: name=123456\r\n");
        str.append(QString("Content-Length:%1\r\n\r\n").arg(contentStr.size()));
        str.append(contentStr);
    }
    
    m_tcpSocket->write(str.toStdString().c_str());
}
