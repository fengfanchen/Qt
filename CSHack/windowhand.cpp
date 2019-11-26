#include "windowhand.h"
#include <QTimerEvent>
#include <QDebug>

WindowHand::WindowHand(QObject *parent) : QObject(parent)
{
    m_hand = nullptr;
    startTimer(1000);
}

void WindowHand::moneyUnmatched()
{
    DWORD base = 0x025069BC;
    DWORD offset1 = 0x7C;
    DWORD offset2 = 0x1CC;

    DWORD value = readMemory(base);
    if(value == 0){

        qDebug() << "WindowHand::moneyUnmatched() base failed";
        return;
    }

    value = readMemory(value + offset1);
    if(value == 0){

        qDebug() << "WindowHand::moneyUnmatched() offset1 failed";
        return;
    }

    writeMemory(value + offset2, 19999);
}

void WindowHand::bloodUnmatched()
{
    DWORD base = 0x025069BC;
    DWORD offset1 = 0x7C;
    DWORD offset2 = 0x4;
    DWORD offset3 = 0x160;

    DWORD value = readMemory(base);
    if(value == 0){

        qDebug() << "WindowHand::bloodUnmatched() base failed";
        return;
    }

    value = readMemory(value + offset1);
    if(value == 0){

        qDebug() << "WindowHand::bloodUnmatched() offset1 failed";
        return;
    }

    value = readMemory(value + offset2);
    if(value == 0){

        qDebug() << "WindowHand::bloodUnmatched() offset2 failed";
        return;
    }

    DWORD dw  = 0;
    float f1 = 255;
    dw = *((DWORD*)&f1);

    writeMemory(value + offset3, dw);
}

void WindowHand::shellUnmatched()
{
    DWORD base = 0x025069BC;
    DWORD offset1 = 0x7C;
    DWORD offset2 = 0x4;
    DWORD offset3 = 0x1BC;

    DWORD value = readMemory(base);
    if(value == 0){

        qDebug() << "WindowHand::shellUnmatched() base failed";
        return;
    }

    value = readMemory(value + offset1);
    if(value == 0){

        qDebug() << "WindowHand::shellUnmatched() offset1 failed";
        return;
    }

    value = readMemory(value + offset2);
    if(value == 0){

        qDebug() << "WindowHand::shellUnmatched() offset2 failed";
        return;
    }

    DWORD dw  = 0;
    float f1 = 255;
    dw = *((DWORD*)&f1);

    writeMemory(value + offset3, dw);
}

void WindowHand::bulletUnmatched()
{
    DWORD base = 0x025069BC;
    DWORD offset1 = 0x7C;
    DWORD offset2 = 0x5EC;
    DWORD offset3 = 0xCC;

    DWORD value = readMemory(base);
    if(value == 0){

        qDebug() << "WindowHand::bulletUnmatched() base failed";
        return;
    }

    value = readMemory(value + offset1);
    if(value == 0){

        qDebug() << "WindowHand::bulletUnmatched() offset1 failed";
        return;
    }

    value = readMemory(value + offset2);
    if(value == 0){

        qDebug() << "WindowHand::bulletUnmatched() offset2 failed";
        return;
    }

    writeMemory(value + offset3, 100);
}

void WindowHand::goUnmatched()
{
    DWORD base = 0x025069BC;
    DWORD offset1 = 0x7C;
    DWORD offset2 = 0x3C4;

    DWORD value = readMemory(base);
    if(value == 0){

        qDebug() << "WindowHand::goUnmatched() base failed";
        return;
    }

    value = readMemory(value + offset1);
    if(value == 0){

        qDebug() << "WindowHand::goUnmatched() offset1 failed";
        return;
    }

    DWORD result = readMemory(value + offset2);
    if(value == 0){

        qDebug() << "WindowHand::goUnmatched() offset2 failed";
        return;
    }

    qDebug() << "result: " << result;

    writeMemory(value + offset2, 1);
}

void WindowHand::grenadeUnmatched()
{
    DWORD base = 0x025069BC;
    DWORD offset1 = 0x7c;
    DWORD offset2 = 0x628;

    DWORD value = readMemory(base);
    if(value == 0){

        qDebug() << "WindowHand::bulletUnmatched() base failed";
        return;
    }

    value = readMemory(value + offset1);
    if(value == 0){

        qDebug() << "WindowHand::bulletUnmatched() offset1 failed";
        return;
    }

    DWORD valueRet = readMemory(value + offset2);
    if(value == 0){

        qDebug() << "WindowHand::bulletUnmatched() offset2 failed";
        return;
    }

    writeMemory(value + offset2, 1);
}

void WindowHand::recoilUnmatched()
{
    DWORD base = 0x025069BC;
    DWORD offset1 = 0x7c;
    DWORD offset2 = 0x4;
    DWORD offset3 = 0x68;

    DWORD value = readMemory(base);
    if(value == 0){

        qDebug() << "WindowHand::recoilUnmatched() base failed";
        return;
    }

    value = readMemory(value + offset1);
    if(value == 0){

        qDebug() << "WindowHand::recoilUnmatched() offset1 failed";
        return;
    }
    value = readMemory(value + offset2);
    if(value == 0){

        qDebug() << "WindowHand::recoilUnmatched() offset1 failed";
        return;
    }

//    qDebug() << readMemory(value + offset3);

    writeMemory(value + offset3, 0);
}

void WindowHand::checkWindowsStatus()
{

    HWND hwnd = FindWindow(nullptr, L"Counter-Strike");
    if(!hwnd){

        emit windowsStatus(false);
        return;
    }

    emit windowsStatus(true);

    DWORD processId;
    GetWindowThreadProcessId(hwnd, &processId);

    m_hand = OpenProcess(PROCESS_ALL_ACCESS, false, processId);

    if(m_hand == nullptr){

        qDebug() << "openProcess failed";
    }

    return;
}

void WindowHand::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    checkWindowsStatus();
}

unsigned long WindowHand::readMemory(unsigned long base)
{
    if(!m_hand){

        qDebug() << "The m_hwnd is null";
        //Q_ASSERT(!"The m_hwnd is null");
        return 0;
    }

    unsigned long ret = 0;
    DWORD dwSize;
    if(0 == ReadProcessMemory(m_hand, (LPVOID)base, &ret, sizeof(DWORD), &dwSize)){

        qDebug() << "ReadProcessMemory failed";
        return ret;
    }
    return ret;
}

void WindowHand::writeMemory(unsigned long base, unsigned long setValue)
{
    if(0 == WriteProcessMemory(m_hand, (LPVOID)(base), &setValue, (DWORD)sizeof(setValue), nullptr)){

        qDebug() << "修改失败";
    }
}
