#include "widget.h"
#include "ui_widget.h"
#include <QTcpServer>
#include <QDebug>
#include <QTcpSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_tcpServer80 = new QTcpServer(this);
    m_tcpServer80->listen(QHostAddress::Any, 80);
    m_tcpServer81 = new QTcpServer(this);
    m_tcpServer81->listen(QHostAddress::Any, 81);

    connect(m_tcpServer80, SIGNAL(newConnection()), this, SLOT(newConnectionSlot80()));
    connect(m_tcpServer81, SIGNAL(newConnection()), this, SLOT(newConnectionSlot81()));

    connect(m_tcpServer80, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(errorStringSlot80()));
    connect(m_tcpServer81, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(errorStringSlot81()));
}

Widget::~Widget()
{
    delete ui;
    m_tcpServer80->close();
    m_tcpServer81->close();
}

void Widget::newConnectionSlot80()
{
    qDebug() << "newConnectionSlot80() called";
    m_tcpSocket80 = m_tcpServer80->nextPendingConnection();
    connect(m_tcpSocket80, SIGNAL(readyRead()), this, SLOT(sendMsg80()));
}

void Widget::newConnectionSlot81()
{
    qDebug() << "newConnectionSlot81() called";
    m_tcpSocket81 = m_tcpServer81->nextPendingConnection();
    connect(m_tcpSocket81, SIGNAL(readyRead()), this, SLOT(sendMsg81()));
}

void Widget::errorStringSlot80()
{
    qDebug() << m_tcpServer80->errorString();
}

void Widget::errorStringSlot81()
{
    qDebug() << m_tcpServer81->errorString();
}

void Widget::sendMsg80()
{
    QString contentStr = "<html>"
                         "<head>"
                         "<title>"
                         "Socket 80"
                         "</title>"
                         "</head>"
                         "<body>"
                         "<h1>Socket 80</h1>"
                         "<script src=\"http://127.0.0.1:81\"></script>"
                         "</body>"
                         "</html>";

    //send msg
    QString str = "HTTP/1.1 200 OK\r\n";
    str.append("Server:nginx\r\n");
    str.append("Content-Type:text/html\r\n");
    str.append("Access-Control-Allow-Origin: *\r\n");
    str.append("Connection:keep-alive\r\n");
    str.append(QString("Content-Length:%1\r\n\r\n").arg(contentStr.size()));
    str.append(contentStr);
    qDebug() << str;
    m_tcpSocket80->write(str.toStdString().c_str());
}

void Widget::sendMsg81()
{
    QString contentStr = "<html>"
                         "<head>"
                         "<title>"
                         "Socket 81"
                         "</title>"
                         "</head>"
                         "<body>"
                         "<h1>Socket 81</h1>"
                         "</body>"
                         "</html>";

    //send msg
    QString str = "HTTP/1.1 200 OK\r\n";
    str.append("Server:nginx\r\n");
    str.append("Content-Type:text/html\r\n");
    str.append("Connection:keep-alive\r\n");
    str.append("Access-Control-Allow-Origin: *\r\n");
    str.append(QString("Content-Length:%1\r\n\r\n").arg(contentStr.size()));
    str.append(contentStr);
    qDebug() << str;
    m_tcpSocket81->write(str.toStdString().c_str());
}
