#ifndef WINDOWHAND_H
#define WINDOWHAND_H

#include <QObject>
#include <windows.h>


class WindowHand : public QObject
{
    Q_OBJECT

public:
    WindowHand(QObject *parent = 0);
    void moneyUnmatched();
    void bloodUnmatched();
    void shellUnmatched();
    void bulletUnmatched();
    void goUnmatched();
    void grenadeUnmatched();
    void recoilUnmatched();

signals:
    void windowsStatus(bool status);

protected:
    void checkWindowsStatus();
    void timerEvent(QTimerEvent *event);
    unsigned long readMemory(unsigned long base);
    void writeMemory(unsigned long base, unsigned long setValue);

protected:
    HANDLE m_hand;
};

#endif // WINDOWHAND_H
