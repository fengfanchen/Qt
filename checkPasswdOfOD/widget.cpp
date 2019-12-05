#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(btnClicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::btnClicked()
{
    QString passwd = ui->lineEdit->text();

    if(isOK(passwd)){


        QMessageBox::information(this, "提示", "成功");
    }
    else{

        QMessageBox::information(this, "提示", "失败");
    }
}

bool Widget::isOK(QString str)
{
    if(str == "www.it1995.cn")
        return true;

    return false;
}
