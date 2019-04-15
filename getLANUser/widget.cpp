#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
#include <QHostInfo>
#include <QDebug>

#define Col1 0
#define Col2 1

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //this->setWindowTitle("CSDN IT1995");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(255);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));
}

Widget::~Widget()
{
    delete ui;
}

int useRow = 0;

void Widget::lookUp(const QHostInfo &host)
{
    if(host.error() != QHostInfo::NoError){

        qDebug() << "Lookup failed:" << host.errorString();
        return;
    }

    if(host.addresses()[0].toString() == host.hostName())
        return;

    QTableWidgetItem *ipItem = new QTableWidgetItem;
    ipItem->setText(host.addresses()[0].toString());
    QTableWidgetItem *hostItem = new QTableWidgetItem;
    hostItem->setText(host.hostName());

    if(ipItem->text() != hostItem->text()){

        ipItem->setTextColor(QColor(Qt::red));
        hostItem->setTextColor(QColor(Qt::red));
    }
    ui->tableWidget->setItem(useRow, Col1, ipItem);
    ui->tableWidget->setItem(useRow, Col2, hostItem);
    useRow++;
}

void Widget::btnClicked()
{
    for(int i = 1 ; i < 256; i++){

        QHostInfo::lookupHost(QString("192.1.101.%1").arg(i), this, SLOT(lookUp(QHostInfo)));
    }
}
