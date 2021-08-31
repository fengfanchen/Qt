#include "Widget.h"
#include "ui_Widget.h"
#include <QImage>
#include <QDebug>
#include <QRandomGenerator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QImage pix(":/tghg.png");
    uchar *oriPtr = pix.bits();

    int picSize = pix.sizeInBytes();
    m_secPtr = new uchar[picSize];
    m_xorPtr = new uchar[picSize];
    m_retPtr = new uchar[picSize];

    //生成密钥图片
    for(int i = 0; i < picSize; i++){

        m_secPtr[i] = QRandomGenerator::global()->bounded(256);
    }

    ui->originLabel->setPixmap(QPixmap::fromImage(pix));
    ui->secLabel->setPixmap(QPixmap::fromImage(QImage(m_secPtr, pix.width(), pix.height(), pix.format())));

    for(int i = 0; i < picSize; i++){

        m_xorPtr[i] = oriPtr[i] ^ m_secPtr[i];
    }

    ui->xorLabel->setPixmap(QPixmap::fromImage(QImage(m_xorPtr, pix.width(), pix.height(), pix.format())));

    //还原
    for(int i = 0; i < picSize; i++){

        m_retPtr[i] = m_xorPtr[i] ^ m_secPtr[i];
    }

    ui->retLabel->setPixmap(QPixmap::fromImage(QImage(m_retPtr, pix.width(), pix.height(), pix.format())));
}

Widget::~Widget()
{
    delete ui;
    delete this->m_retPtr;
    delete this->m_secPtr;
    delete this->m_xorPtr;
}

