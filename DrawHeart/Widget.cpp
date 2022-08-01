#include "Widget.h"
#include "ui_Widget.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <QPen>
#include <iostream>
#include <QtMath>
#include <QGraphicsScene>
#include <QDebug>
#include <QPoint>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    m_scene = new QGraphicsScene;
    ui->graphicsView->setScene(m_scene);
    drawCricle(-100, 0, 200, 200, 0, 360 * 10);
    drawCricle(100, 0, 200, 200, 360 * 14, 360 * 10);
    drawPolygon();
    this->setWindowTitle("it1995.cn Designed by FengFanChen");
}

Widget::~Widget()
{
    delete m_scene;
    delete ui;
}

void Widget::drawCricle(int x, int y, int height, int width, int startAngle, int endAngle)
{
    auto item(new QGraphicsEllipseItem(x, y, height, width));
    item->setBrush(Qt::red);
    item->setStartAngle(startAngle);
    item->setSpanAngle(endAngle);
    item->setPen(QPen(Qt::red));
    m_scene->addItem(item);
}

void Widget::drawPolygon()
{
    double oneCricleHeartX = -2.5;
    double oneCricleHeartY = 95;
    double oneX = oneCricleHeartX + 100 * cos(135 * ( M_PI /180));
    double oneY = oneCricleHeartY + 100 * sin(135 * ( M_PI /180));

    double endX = 100;
    double endY = 100 + 200;
//    auto item(new QGraphicsEllipseItem(x, y, 10, 10));
    //auto item(new QGraphicsEllipseItem(100 - 5, 100 - 5 + 100, 10, 10));
//    auto item(new QGraphicsEllipseItem(endX, endY, 10, 10));
//    item->setBrush(Qt::blue);
//    m_scene->addItem(item);


//    auto line1Item(new QGraphicsLineItem(oneX, oneY + 2.5, endX + 1, endY + 1));
//    m_scene->addItem(line1Item);

    //第二个
    double twoCricleHeartX = 200;
    double twoCricleHeartY = 95;
//    auto item(new QGraphicsEllipseItem(twoCricleHeartX - 5, twoCricleHeartY, 10, 10));
//    item->setBrush(Qt::blue);
//    m_scene->addItem(item);

    double twoX = twoCricleHeartX + 100 * cos(45 * ( M_PI /180));
    double twoY = twoCricleHeartY + 100 * sin(45 * ( M_PI /180));
//    auto item(new QGraphicsEllipseItem(twoX - 5, twoY, 10, 10));
//    item->setBrush(Qt::blue);
//    m_scene->addItem(item);
//    auto line2Item(new QGraphicsLineItem(twoX, twoY + 5, endX + 1, endY + 1));
//    m_scene->addItem(line2Item);

    auto polygonItem = (new QGraphicsPolygonItem());
    QPolygonF pf;
    pf.append(QPoint(endX + 1, endY + 1));
    pf.append(QPoint(oneX + 2, oneY + 5));
    pf.append(QPoint(oneCricleHeartX, oneCricleHeartY + 5));
    pf.append(QPoint(twoCricleHeartX, twoCricleHeartY + 5));
    pf.append(QPoint(twoX, twoY + 5));
    polygonItem->setPolygon(pf);
    polygonItem->setPen(QPen(Qt::red));
    polygonItem->setBrush(Qt::red);
    m_scene->addItem(polygonItem);
}

