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
    connect(m_tcpServer80, SIGNAL(newConnection()), this, SLOT(newConnectionSlot80()));
    connect(m_tcpServer80, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(errorStringSlot80()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));
}

Widget::~Widget()
{
    delete ui;
    m_tcpServer80->close();
}

void Widget::newConnectionSlot80()
{
    qDebug() << "newConnectionSlot80() called";
    m_tcpSocket80 = m_tcpServer80->nextPendingConnection();
    sendMsg80();
    //connect(m_tcpSocket80, SIGNAL(readyRead()), this, SLOT(sendMsg80()));
    //connect(m_tcpSocket80, SIGNAL(connected()), this, SLOT(sendMsg80()));
}

void Widget::errorStringSlot80()
{
    qDebug() << m_tcpServer80->errorString();
}

void Widget::sendMsg80()
{
    QString contentStr;
    QString str;
    if(ui->pushButton->text() == "正常回HTTP包"){

        contentStr = "<html>"
                     "<head>"
                     "<title>"
                     "Socket 80"
                     "</title>"
                     "</head>"
                     "<body>"
                     "<h1>Socket 80</h1>"
                     "</body>"
                     "</html>";

        //send msg
        str = "HTTP/1.1 200 OK\r\n";
        str.append("Server:nginx\r\n");
        str.append("Content-Type:text/html\r\n");
        str.append("Access-Control-Allow-Origin: *\r\n");
        str.append("Connection:keep-alive\r\n");
        str.append("Cache-Control: max-age=200000\r\n");
        str.append("Last-Modified: 777777\r\n");
        str.append("Etage: 888888\r\n");
        str.append(QString("Content-Length:%1\r\n\r\n").arg(contentStr.size()));
        str.append(contentStr);
        //qDebug() << str;
    }
    else{

        str = "HTTP/1.1 304 OK\r\n";
        str.append("Server:nginx\r\n");
        str.append("Content-Type:text/html\r\n");
        str.append("Access-Control-Allow-Origin: *\r\n");
        str.append("Connection:keep-alive\r\n");
        str.append("Cache-Control: max-age=200000, no-cache\r\n");
        str.append("Last-Modified: 777777\r\n");
        str.append("Etage: 888888\r\n");
        str.append(QString("Content-Length:%1\r\n\r\n").arg(contentStr.size()));
    }

    m_tcpSocket80->write(str.toStdString().c_str());
}

void Widget::btnClicked()
{
    if(ui->pushButton->text() == "正常回HTTP包"){

        ui->pushButton->setText("回304包");
    }
    else{

        ui->pushButton->setText("正常回HTTP包");
    }
}
