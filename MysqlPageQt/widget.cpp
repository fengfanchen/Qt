#include "widget.h"
#include "ui_widget.h"
#include "sql.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_sql = new SQL;

    m_count = m_sql->getCount();
    ui->countLabel->setText(QString::number(m_count) + " 行");
    m_currentPage = 1;
    m_countPage = 1;
    m_numInPage = 0;
    updateBtnStatus();
    this->setWindowTitle("CSDN IT1995");

    connect(ui->numSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueChange(int)));
    connect(ui->upPushButton, SIGNAL(clicked()), this, SLOT(upBtnClicked()));
    connect(ui->downPushButton, SIGNAL(clicked()), this, SLOT(downBtnClicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateBtnStatus()
{
    if(ui->numSpinBox->value() == 0){

        ui->upPushButton->setEnabled(false);
        ui->downPushButton->setEnabled(false);
        return;
    }


    //if(m_currentPage < m_countPage && m_currentPage != 1){
    qDebug() << "m_countPage:" << m_countPage;
    if(m_currentPage == m_countPage){

        ui->downPushButton->setEnabled(false);
        ui->upPushButton->setEnabled(true);
    }
    else if(m_currentPage == 1){

        ui->downPushButton->setEnabled(true);
        ui->upPushButton->setEnabled(false);
    }
    else{

        ui->upPushButton->setEnabled(true);
        ui->downPushButton->setEnabled(true);

//        ui->downPushButton->setEnabled(false);
//        ui->upPushButton->setEnabled(true);
    }
}

void Widget::setTreeWidget()
{
    int start = (m_currentPage - 1) * m_numInPage;
    int num = m_numInPage;
    QVector<QStringList> localLimitSql = m_sql->limitSql(start, num);

    ui->treeWidget->clear();
    if(localLimitSql.size() == 0){

        qDebug() << "The localLimitSql.size() is 0";
        return;
    }

    ui->treeWidget->setHeaderLabels(localLimitSql[0]);
    for(int i = 1; i < localLimitSql.size(); i++){

        QTreeWidgetItem *item = new QTreeWidgetItem;
        item->setText(0, localLimitSql[i][0]);
        item->setText(1, localLimitSql[i][1]);
        item->setText(2, localLimitSql[i][2]);
        ui->treeWidget->insertTopLevelItem(i - 1, item);
    }
}

void Widget::valueChange(int num)
{
    m_numInPage = ui->numSpinBox->value();
    updateBtnStatus();
    if(num == 0){

        return;
    }

    int page = ceil(m_count / (double)num);
    ui->pageLabel->setText("1/" + QString::number(page));
    m_countPage = page;
    setTreeWidget();
}

void Widget::upBtnClicked()
{
    m_currentPage--;
    updateBtnStatus();
    qDebug() << "upBtnClicked the m_currentPage is " << m_currentPage;
    setTreeWidget();
    ui->pageLabel->setText(QString::number(m_currentPage) + "/" + QString::number(m_countPage));
}

void Widget::downBtnClicked()
{
    m_currentPage++;
    updateBtnStatus();
    qDebug() << "downBtnClicked the m_currentPage is " << m_currentPage;
    setTreeWidget();
    ui->pageLabel->setText(QString::number(m_currentPage) + "/" + QString::number(m_countPage));
}
