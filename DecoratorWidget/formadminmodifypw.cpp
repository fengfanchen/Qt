#include "formadminmodifypw.h"
#include "ui_formadminmodifypw.h"

FormAdminModifyPW::FormAdminModifyPW(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAdminModifyPW)
{
    ui->setupUi(this);
    this->setWindowTitle("修改管理员密码");
}

FormAdminModifyPW::~FormAdminModifyPW()
{
    delete ui;
}
