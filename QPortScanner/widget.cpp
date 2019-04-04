#include "widget.h"
#include "ui_widget.h"

#include <QMouseEvent>
#include <QMessageBox>
#include <QFile>
#include <QRegExp>
#include <QRegExpValidator>
#include <QEvent>
#include <QDateTime>
#include <QTimer>
#include <QRect>
#include <QDesktopWidget>
#include <QDebug>

#include "mynetwork.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->timeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+" BLOG: CSDN IT1995 QQ:570176391");
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->titleLabel->setText("端口扫描器 v1.0");
    this->setWindowTitle("端口扫描器 v1.0");

    QFile myFile;
    myFile.setFileName(":/img/myQSS.txt");
    myFile.open(QFile::ReadOnly);
    QString styleSheet=QString(myFile.readAll());
    qApp->setStyleSheet(styleSheet);
    myFile.close();
    QRect sceenRect=QApplication::desktop()->screenGeometry();
    setFixedSize(sceenRect.width()/4,sceenRect.height()/2);


    m_pTimer=new QTimer(this);
    connect(m_pTimer,SIGNAL(timeout()),this,SLOT(showDynamicTime()));
    m_pTimer->start(1000);

    ui->closeLabel->setStatus(CloseLabel);
    ui->minLabel->setStatus(MinLabel);

    for(int i=0;i<10;i++){
        m_netWork[i]=new MyNetWork;
    }

    ui->progressBar->hide();

    QRegExp regExp("^[.|0-9|^]{1,15}$");
    QRegExpValidator *pattern=new QRegExpValidator(regExp,this);
    ui->ipLineEdit->setValidator(pattern);


    connect(ui->closeLabel,SIGNAL(prepareToClose()),this,SLOT(windowsClose()));
    connect(ui->minLabel,SIGNAL(prepareToMin()),this,SLOT(windowsShowMin()));
    connect(ui->startPushButton,SIGNAL(clicked(bool)),this,SLOT(btnClicked()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    QPoint y=event->globalPos();
    QPoint x=y-z;
    this->move(x);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    QPoint y=event->globalPos();
    QPoint x=this->geometry().topLeft();
    z=y-x;
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    z=QPoint();
}

bool Widget::checkIpLineEditProperty()
{
    QStringList list=ui->ipLineEdit->text().split(".");
    if(list.size()!=4)
        return false;
    if((list[0].toInt()>255||list[0].toInt()<0)
            ||(list[1].toInt()>255||list[1].toInt()<0)
            ||(list[2].toInt()>255||list[2].toInt()<0)
            ||(list[3].toInt()>255||list[3].toInt()<0))
        return false;

    return true;
}

void Widget::showDynamicTime()
{
    ui->timeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+" BLOG: CSDN IT1995 QQ:570176391");
}

void Widget::windowsClose()
{
    this->close();
}

void Widget::windowsShowMin()
{
    this->showMinimized();
}

void Widget::btnClicked()
{
    if(!checkIpLineEditProperty()){
        QMessageBox::information(this,"提示","IP地址输入有误");
        return;
    }
    int intervalData=(ui->startSpinBox->value()+ui->endSpinBox->value())/10+1;
    int threadStartPort=ui->startSpinBox->value();
    int threadEndPort=threadStartPort+intervalData;

    //10线程端口分配
    for(int i=0;i<10;i++){
        if(i==0){
            m_netWork[0]->setIp(ui->ipLineEdit->text());
            m_netWork[0]->setStartPort(threadStartPort);
            m_netWork[0]->setEndPort(threadEndPort);
            continue;
        }
        m_netWork[i]->setIp(ui->ipLineEdit->text());
        threadStartPort=threadEndPort+1;
        threadEndPort=threadEndPort+intervalData;
        m_netWork[i]->setStartPort(threadStartPort);
        if(threadEndPort>=ui->endSpinBox->value()){
            m_netWork[i]->setEndPort(ui->endSpinBox->value());
            break;
        }
        m_netWork[i]->setEndPort(threadEndPort);
    }
    ui->progressBar->show();
    ui->progressBar->setValue(0);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(ui->endSpinBox->value()-ui->startSpinBox->value()+1);
    ui->successListWidget->clear();

    m_sucessPort.clear();

    for(int i=0;i<10;i++){
        QTimer::singleShot(0,m_netWork[i],SLOT(beginToScanner()));
        connect(m_netWork[i],SIGNAL(progressBarAdd()),this,SLOT(progressBarIncreament()));
        connect(m_netWork[i],SIGNAL(pcIsConnected(int)),this,SLOT(updateListWidget(int)));
    }
}

void Widget::progressBarIncreament()
{
    ui->progressBar->setValue(ui->progressBar->value()+1);
    if(ui->progressBar->value()==ui->progressBar->maximum()){
        ui->progressBar->hide();
    }
}

void Widget::updateListWidget(int port)
{
    ui->successListWidget->clear();
    m_sucessPort.insert(port,ui->ipLineEdit->text());
    QMapIterator<int,QString> i(m_sucessPort);
      while(i.hasNext()){
          i.next();
          QString msg="IP:  "+i.value()+"  port: "+QString::number(i.key());
          msg.append(" successfully!");
          ui->successListWidget->insertItem(0,msg);
      }
}
