#include "loginweb.h"
#include <QWebView>
#include <QWebSettings>
#include <QTimerEvent>
#include <QNetworkCookie>
#include <QNetworkCookieJar>
#include <QDebug>
#include <QUrl>

LoginWeb::LoginWeb(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.webView->setUrl(QUrl("https://passport.csdn.net/login?code=public"));
	QWebSettings *settings = ui.webView->settings();
	settings->setAttribute(QWebSettings::LocalStorageEnabled, true);
	startTimer(1000);
}

LoginWeb::~LoginWeb()
{

}

void LoginWeb::timerEvent(QTimerEvent *event)
{
	QList<QNetworkCookie> list = ui.webView->page()->networkAccessManager()->cookieJar()->cookiesForUrl(QUrl("https://www.csdn.net/"));
	for(int i = 0; i < list.size(); i++){


		qDebug() << list[i].name() << "\t" << list[i].value();
	}
	qDebug() << QString::fromLocal8Bit("--------- 华 丽 的 分 割 线 ---------");
}
