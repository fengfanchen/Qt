#include "widget.h"
#include "ui_widget.h"
#include <QCompleter>
#include <QDirModel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList wordList;
    wordList << "alpha" << "omega" << "omicron" << "zeta" << "中文" << "中文中文中文中文";
    QCompleter *completer1 = new QCompleter(wordList, this);
    completer1->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer1);

    QCompleter *completer2 = new QCompleter(this);
    completer2->setModel(new QDirModel(completer2));
    ui->lineEdit_2->setCompleter(completer2);

    for(int i = 0; completer1->setCurrentRow(i); i++){

        qDebug() << completer1->currentCompletion() << " is match number " << i;
    }
}

Widget::~Widget()
{
    delete ui;
}

