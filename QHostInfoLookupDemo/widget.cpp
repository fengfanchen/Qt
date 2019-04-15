#include "widget.h"
#include "ui_widget.h"
#include <QHostInfo>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    for(int i = 0; i < 256; i++){
//        QHostInfo::lookupHost(QString("192.1.101.%1").arg(i), this, SLOT(lookUp(QHostInfo)));
//    }

    QHostInfo::lookupHost("www.baidu.com", this, SLOT(lookUp(QHostInfo)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::lookUp(const QHostInfo &host)
{
    if(host.error() != QHostInfo::NoError){

        qDebug() << "Lookup failed: " << host.errorString();
        return;
    }


    const auto addresses = host.addresses();
    for(const QHostAddress &address : addresses){

        qDebug() << "address:" << address.toString() << "  hostname:" << host.hostName();
    }
}
