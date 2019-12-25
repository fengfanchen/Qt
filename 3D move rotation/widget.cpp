#include "widget.h"
#include "ui_widget.h"
#include <QtDataVisualization/QScatter3DSeries>
#include <QDebug>
#include <QThread>
#include <QTime>
#include <QTimer>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("CSDN IT1995");
    m_graph = new Q3DScatter();
    m_graph->axisX()->setRange(-10, 10);
    m_graph->axisY()->setRange(-10, 10);
    m_graph->axisZ()->setRange(-10, 10);
    QWidget *container = QWidget::createWindowContainer(m_graph);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    if (!m_graph->hasContext()) {

        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        msgBox.exec();
        return;
    }



    //添加数据
    QScatter3DSeries *item = new QScatter3DSeries();
    item->setMesh(QAbstract3DSeries::MeshUserDefined);
    item->setUserDefinedMesh(":/img/1cube.obj");

    m_graph->addSeries(item);


    //设置到控件上
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(container, 1);
    ui->widget->setLayout(hLayout);

    //生成线，数据：
    QScatterDataArray *dataArray = new QScatterDataArray;
    dataArray->resize(5);
    QScatterDataItem *ptrToDataArray = &dataArray->first();

    for(int i = 0; i <= dataArray->size(); i++){

        ptrToDataArray->setPosition(QVector3D(0, i, 0));
        ptrToDataArray++;
    }

    item->dataProxy()->resetArray(dataArray);

    //让其随机移动
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, [=](){

        QScatterDataItem *ptr = &dataArray->first();

        for(int i = 0; i < dataArray->size(); i++){

            ptr->setPosition(QVector3D(qrand()%8 > 4 ? qrand()%8 : -qrand()%8, qrand()%8 > 4 ? qrand()%8 : -qrand()%8, qrand()%8 > 4 ? qrand()%8 : -qrand()%8));
            ptr++;
        }
        item->dataProxy()->resetArray(dataArray);
    });
    m_timer->start(2000);

    //让其自身旋转
    m_rotationTimer = new QTimer(this);
    connect(m_rotationTimer, &QTimer::timeout, [=]() mutable{

        QScatterDataItem *ptr = &dataArray->first();

        for(int i = 0; i < dataArray->size(); i++){

            QQuaternion ruaternion = QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 1.0f), qrand()%600);
            ptr->setRotation(ruaternion);
            ptr++;
        }
        item->dataProxy()->resetArray(dataArray);
    });
    m_rotationTimer->start(100);
}

Widget::~Widget()
{
    qDebug() << "Widget::~Widget()";
    delete m_graph;
    delete ui;
}

void Widget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    m_timer->stop();
    m_rotationTimer->stop();
    QThread::sleep(2);
}
