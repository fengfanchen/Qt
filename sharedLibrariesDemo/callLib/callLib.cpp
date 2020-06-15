#include "callLib.h"
#include "ui_callLib.h"
#include <libDemo_global.h>
#include <LibDemo.h>

callLib::callLib(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::callLib)
{
    ui->setupUi(this);
    m_lib = new LibDemo;
    m_lib->showNewWidgets();
}

callLib::~callLib()
{
    m_lib->freeWidgets();
    delete m_lib;
    delete ui;
}

