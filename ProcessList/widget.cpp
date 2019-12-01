#include "widget.h"
#include "ui_widget.h"
#include "thread.h"
#include <QDebug>
#include <QTableWidgetItem>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_thread = new Thread;

    QStringList headList;
    headList << "进程ID" << "     进程名     " << "父类进程ID" << "进程句柄" << "优先级";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(headList);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setColumnWidth(1, 150);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);


    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setShowGrid(false);


    startTimer(1000);
}

Widget::~Widget()
{
    delete ui;
    delete m_thread;
}

void Widget::addNew()
{
    QVector<ProcessInfo> vec = m_thread->getVec();


    for(ProcessInfo info : vec){

        bool have = false;
        for(int i = 0; i < ui->tableWidget->rowCount(); i++){

            if(ui->tableWidget->item(i, 0)->text() == info.processID){

               have = true;
            }
        }
        if(!have){

            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0, 0, new QTableWidgetItem(info.processID));
            ui->tableWidget->setItem(0, 1, new QTableWidgetItem(info.processName));
            ui->tableWidget->setItem(0, 2, new QTableWidgetItem(info.parentProcessID));
            ui->tableWidget->setItem(0, 3, new QTableWidgetItem(info.processHandle));
            ui->tableWidget->setItem(0, 4, new QTableWidgetItem(info.processPri));
        }
    }
}

void Widget::removeOld()
{
    QVector<ProcessInfo> vec = m_thread->getVec();


    for(int i = 0; i < ui->tableWidget->rowCount(); i++){

        bool have = false;
        for(ProcessInfo info : vec){

            if(info.processID == ui->tableWidget->item(i, 0)->text()){

                have = true;
                continue;
            }
        }

        if(!have){

            ui->tableWidget->removeRow(i);
        }
    }
}

void Widget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    m_thread->clearVec();
    m_thread->getSnapshot();
    addNew();
    removeOld();
}
