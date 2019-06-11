#include "formadminintroduce.h"
#include "ui_formadminintroduce.h"

FormAdminIntroduce::FormAdminIntroduce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAdminIntroduce)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员门户界面");
}

FormAdminIntroduce::~FormAdminIntroduce()
{
    delete ui;
}
