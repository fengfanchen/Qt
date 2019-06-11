#include "formuserintroduce.h"
#include "ui_formuserintroduce.h"

FormUserIntroduce::FormUserIntroduce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUserIntroduce)
{
    ui->setupUi(this);
    this->setWindowTitle("用户简介");
}

FormUserIntroduce::~FormUserIntroduce()
{
    delete ui;
}
