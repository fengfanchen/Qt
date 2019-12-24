#include "widget.h"
#include "ui_widget.h"
#include <QtDataVisualization/Q3DScatter>
#include <QtDataVisualization/QCustom3DItem>
#include <QDebug>
#include <QMessageBox>

using namespace QtDataVisualization;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("CSDN IT1995");
    Q3DScatter *graph = new Q3DScatter();
    QWidget *container = QWidget::createWindowContainer(graph);

    if (!graph->hasContext()) {

        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        msgBox.exec();
        return;
    }



    //添加数据
    QCustom3DItem *item = new QCustom3DItem();
    item->setScaling(QVector3D(0.03f, 0.03f, 0.03f));
    item->setMeshFile(":/img/oo.obj");

    qDebug() << "The ret is : " << graph->addCustomItem(item);



    //设置到控件上
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(container, 1);
    ui->widget->setLayout(hLayout);
}

Widget::~Widget()
{
    delete ui;
}
