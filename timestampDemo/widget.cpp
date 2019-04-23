#include "widget.h"
#include "ui_widget.h"
#include <QTime>
#include <QDateTime>
#include <QDebug>
#include <QDate>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    startTimer(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    uint currentDataInt = QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-M-dd"), "yyyy-M-dd").toTime_t();
    uint currentTimeInt = QDateTime::currentDateTime().toTime_t();
    qDebug() << "当天: " << currentDataInt;
    qDebug() << "现在: " << currentTimeInt;
    qDebug() << "目前写入点："  << (currentTimeInt - currentDataInt)/300;

    qDebug() << "-------------华丽的分割线-------------";
}
