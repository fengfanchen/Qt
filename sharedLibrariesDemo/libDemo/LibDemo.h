#ifndef LIBDEMO_H
#define LIBDEMO_H

#include "libDemo_global.h"

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

class LIBDEMO_EXPORT LibDemo
{
public:
    LibDemo();
    void showNewWidgets();
    void freeWidgets();

private:
    QWidget *m_btn;
};

#endif // LIBDEMO_H
