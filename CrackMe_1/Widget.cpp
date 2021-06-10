#include "Widget.h"
#include "ui_Widget.h"
#include "Data.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText(QString::number(resource));
    this->setWindowTitle("crackMe_1");
    startTimer(1000);

    qDebug() << "resource address:" << &resource;
}

void Widget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)

    if(resource <= 0){

        QMessageBox::information(this, "title", "game over");
        exit(-1);
    }

    ui->label->setText(QString::number(--resource));
}

Widget::~Widget()
{
    delete ui;
}

