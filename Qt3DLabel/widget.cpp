#include "widget.h"
#include "ui_widget.h"
#include <QtDataVisualization>
#include <QCustom3DLabel>
#include <QList>
#include <QPropertyAnimation>
#include <QFont>
#include <QVector3D>
#include <QDebug>

using namespace QtDataVisualization;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_surface = new Q3DSurface;
    this->setWindowTitle("CSDN IT1995");
    createLabel("Hello World");
    m_selectionAnimation = new QPropertyAnimation(this);
    m_selectionAnimation->setPropertyName("scaling");
    m_selectionAnimation->setDuration(500);
    m_selectionAnimation->setLoopCount(-1);

    QWidget *w = QWidget::createWindowContainer(m_surface);
    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(w);
    ui->widget->setLayout(lay);

    connect(m_surface, &QAbstract3DGraph::selectedElementChanged, this, &Widget::handleElementSelected);
    connect(ui->pushButton, &QPushButton::clicked, [=](){

        m_surface->removeCustomItem(m_label);
        createLabel(ui->lineEdit->text());
    });
}

Widget::~Widget()
{
    delete m_surface;
    delete ui;
}

void Widget::handleElementSelected(int type)
{
    if(type == QAbstract3DGraph::ElementCustomItem){

        QCustom3DItem *item = m_surface->selectedCustomItem();
        QCustom3DLabel *p = qobject_cast<QCustom3DLabel *>(item);
        if(p != nullptr){

            ui->lineEdit->setText(p->text());
            m_selectionAnimation->setTargetObject(item);
            m_selectionAnimation->setStartValue(item->scaling());
            m_selectionAnimation->setEndValue(item->scaling() * 1.5f);
            m_selectionAnimation->start();
        }
    }
    else if(type == QAbstract3DGraph::ElementSeries){

    }
    else if(type == QAbstract3DGraph::ElementAxisXLabel){

        ui->lineEdit->setText("X Label clicked");
    }
    else if(type == QAbstract3DGraph::ElementAxisYLabel){

        ui->lineEdit->setText("Y Label clicked");
    }
    else if(type == QAbstract3DGraph::ElementAxisZLabel){

        ui->lineEdit->setText("Z Label clicked");
    }
}

void Widget::createLabel(const QString text)
{
    QFont titleFont = QFont("Century Gothic", 30);
    titleFont.setBold(true);
    m_label = new QCustom3DLabel(text, titleFont, QVector3D(0.0f, 1.2f, 0.0f), QVector3D(1.0f, 1.0f, 0.0f), QQuaternion());
    m_label->setPositionAbsolute(true);
    m_label->setFacingCamera(true);
    m_label->setBackgroundColor(QColor(0x66cdaa));
    m_surface->addCustomItem(m_label);
}

