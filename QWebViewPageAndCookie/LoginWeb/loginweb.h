#ifndef LOGINWEB_H
#define LOGINWEB_H

#include <QtWidgets/QWidget>
#include "ui_loginweb.h"

class LoginWeb : public QWidget
{
	Q_OBJECT

public:
	LoginWeb(QWidget *parent = 0);
	~LoginWeb();

protected:
	void timerEvent(QTimerEvent *event);

private:
	Ui::LoginWebClass ui;
};

#endif // LOGINWEB_H
