#ifndef CALLLIB_H
#define CALLLIB_H

#include <QWidget>

class LibDemo;

QT_BEGIN_NAMESPACE
namespace Ui { class callLib; }
QT_END_NAMESPACE

class callLib : public QWidget
{
    Q_OBJECT

public:
    callLib(QWidget *parent = nullptr);
    ~callLib();

private:
    Ui::callLib *ui;
    LibDemo *m_lib;
};
#endif // CALLLIB_H
