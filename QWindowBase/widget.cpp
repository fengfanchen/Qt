#include "widget.h"
#include "ui_widget.h"
#include "window.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("CSDN IT1995");
    m_window = new Window;
    QWidget *widget = QWidget::createWindowContainer(m_window);
    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(widget);
    ui->widget->setLayout(lay);
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), m_window, SLOT(getMsg(QString)));
}

Widget::~Widget()
{
    delete m_window;
    delete ui;
}
