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
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected slots:
    void newConnectionSlot80();
    void newConnectionSlot81();

    void errorStringSlot80();
    void errorStringSlot81();

    void sendMsg80();
    void sendMsg81();

private:
    Ui::Widget *ui;
    QTcpServer *m_tcpServer80;
    QTcpSocket *m_tcpSocket80;

    QTcpServer *m_tcpServer81;
    QTcpSocket *m_tcpSocket81;
};

#endif // WIDGET_H
