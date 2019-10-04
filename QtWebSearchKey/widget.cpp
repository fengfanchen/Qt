#include "widget.h"
#include "ui_widget.h"
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QMap>
#include <QVariant>
#include <QDebug>
#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("CSDN IT1995");
    m_manager = new QNetworkAccessManager(this);
    connect(ui->lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(inputChanged(const QString&)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::inputChanged(const QString &text)
{
    QNetworkRequest request;
    request.setUrl("https://www.baidu.com/sugrec?pre=1&p=3&ie=utf-8&json=1&prod=pc&from=pc_web&sugsid=1430,21123,29523,29721,29567,29220&req=2&csor=5&pwd=123&wd=" + text);
    QNetworkReply *reply = m_manager->get(request);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QMap<QString, QVariant> map = QJsonDocument().fromJson(reply->readAll()).toVariant().toMap();
    //map = map.value("g").toMap();
    QList<QVariant> list = map.value("g").toList();
    QStringList widgetList;
    for(int i = 0; i < list.size(); i++){

        widgetList << list[i].toMap().value("q").toString();
    }

    resetListWidget(widgetList);
}

void Widget::resetListWidget(QStringList list)
{
    ui->listWidget->clear();
    ui->listWidget->addItems(list);
}
