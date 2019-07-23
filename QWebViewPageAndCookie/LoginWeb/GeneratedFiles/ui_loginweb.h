/********************************************************************************
** Form generated from reading UI file 'loginweb.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWEB_H
#define UI_LOGINWEB_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWebClass
{
public:
    QVBoxLayout *verticalLayout;
    QWebView *webView;

    void setupUi(QWidget *LoginWebClass)
    {
        if (LoginWebClass->objectName().isEmpty())
            LoginWebClass->setObjectName(QStringLiteral("LoginWebClass"));
        LoginWebClass->resize(600, 400);
        verticalLayout = new QVBoxLayout(LoginWebClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        webView = new QWebView(LoginWebClass);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        verticalLayout->addWidget(webView);


        retranslateUi(LoginWebClass);

        QMetaObject::connectSlotsByName(LoginWebClass);
    } // setupUi

    void retranslateUi(QWidget *LoginWebClass)
    {
        LoginWebClass->setWindowTitle(QApplication::translate("LoginWebClass", "LoginWeb", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWebClass: public Ui_LoginWebClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWEB_H
