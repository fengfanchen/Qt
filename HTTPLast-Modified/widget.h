#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTcpServer;
class QTcpSocket;
QT_END_NAMESPACE

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected slots:
    void newConnectionSlot80();
    void errorStringSlot80();
    void sendMsg80();
    void btnClicked();

private:
    Ui::Widget *ui;
    QTcpServer *m_tcpServer80;
    QTcpSocket *m_tcpSocket80;

};

#endif // WIDGET_H
