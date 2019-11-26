#include "widget.h"
#include "ui_widget.h"
#include "windowhand.h"
#include "qxtglobalshortcut.h"
#include <QDebug>
#include <windows.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_windowHand = new WindowHand(this);
    setWidgetStatus(false);
    startTimer(50);

    this->setWindowTitle("CSDN IT1995");
    connect(m_windowHand, SIGNAL(windowsStatus(bool)), this, SLOT(setStatusString(bool)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setWidgetStatus(bool status)
{
    if(status){

        ui->bloodCheckBox->setEnabled(true);
        ui->shellCheckBox->setEnabled(true);
        ui->moneyCheckBox->setEnabled(true);
        ui->bulletCheckBox->setEnabled(true);
        ui->grenadeCheckBox->setEnabled(true);
        ui->recoilCheckBox->setEnabled(true);
//        ui->goCheckBox->setEnabled(true);
    }
    else{

        ui->bloodCheckBox->setEnabled(false);
        ui->shellCheckBox->setEnabled(false);
        ui->moneyCheckBox->setEnabled(false);
        ui->bulletCheckBox->setEnabled(false);
        ui->grenadeCheckBox->setEnabled(false);
        ui->recoilCheckBox->setEnabled(false);
//        ui->goCheckBox->setEnabled(false);
    }
}

void Widget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    if(ui->moneyCheckBox->isEnabled() && ui->moneyCheckBox->checkState() == Qt::Checked){

        m_windowHand->moneyUnmatched();
    }
    if(ui->bloodCheckBox->isEnabled() && ui->bloodCheckBox->checkState() == Qt::Checked){

        m_windowHand->bloodUnmatched();
    }
    if(ui->shellCheckBox->isEnabled() && ui->shellCheckBox->checkState() == Qt::Checked){

        m_windowHand->shellUnmatched();
    }
    if(ui->bulletCheckBox->isEnabled() && ui->bulletCheckBox->checkState() == Qt::Checked){

        m_windowHand->bulletUnmatched();
    }
    if(ui->grenadeCheckBox->isEnabled() && ui->grenadeCheckBox->checkState() == Qt::Checked){

        m_windowHand->grenadeUnmatched();
    }
//    if(ui->goCheckBox->isEnabled() && ui->goCheckBox->checkState() == Qt::Checked){

//        m_windowHand->goUnmatched();
//    }
    if(ui->recoilCheckBox->isEnabled() && ui->recoilCheckBox->checkState() == Qt::Checked){

        m_windowHand->recoilUnmatched();
    }
}

void Widget::setStatusString(bool status)
{
    if(status){

        ui->statusLabel->setText("游戏已经运行...ing...");
    }
    else{

        ui->statusLabel->setText("未检测到游戏运行...");
    }

    setWidgetStatus(status);
}
