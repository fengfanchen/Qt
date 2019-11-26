/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *bloodCheckBox;
    QCheckBox *shellCheckBox;
    QCheckBox *moneyCheckBox;
    QCheckBox *bulletCheckBox;
    QCheckBox *grenadeCheckBox;
    QCheckBox *recoilCheckBox;
    QCheckBox *goCheckBox;
    QSpacerItem *verticalSpacer;
    QLabel *statusLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(225, 210);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        bloodCheckBox = new QCheckBox(Widget);
        bloodCheckBox->setObjectName(QStringLiteral("bloodCheckBox"));

        verticalLayout->addWidget(bloodCheckBox);

        shellCheckBox = new QCheckBox(Widget);
        shellCheckBox->setObjectName(QStringLiteral("shellCheckBox"));

        verticalLayout->addWidget(shellCheckBox);

        moneyCheckBox = new QCheckBox(Widget);
        moneyCheckBox->setObjectName(QStringLiteral("moneyCheckBox"));

        verticalLayout->addWidget(moneyCheckBox);

        bulletCheckBox = new QCheckBox(Widget);
        bulletCheckBox->setObjectName(QStringLiteral("bulletCheckBox"));

        verticalLayout->addWidget(bulletCheckBox);

        grenadeCheckBox = new QCheckBox(Widget);
        grenadeCheckBox->setObjectName(QStringLiteral("grenadeCheckBox"));

        verticalLayout->addWidget(grenadeCheckBox);

        recoilCheckBox = new QCheckBox(Widget);
        recoilCheckBox->setObjectName(QStringLiteral("recoilCheckBox"));

        verticalLayout->addWidget(recoilCheckBox);

        goCheckBox = new QCheckBox(Widget);
        goCheckBox->setObjectName(QStringLiteral("goCheckBox"));

        verticalLayout->addWidget(goCheckBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        statusLabel = new QLabel(Widget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        verticalLayout->addWidget(statusLabel);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        bloodCheckBox->setText(QApplication::translate("Widget", "\346\227\240\351\231\220\350\241\200\351\207\217", 0));
        shellCheckBox->setText(QApplication::translate("Widget", "\346\227\240\351\231\220\351\230\262\345\274\271\350\241\243", 0));
        moneyCheckBox->setText(QApplication::translate("Widget", "\346\227\240\351\231\220\351\207\221\351\222\261", 0));
        bulletCheckBox->setText(QApplication::translate("Widget", "\346\227\240\351\231\220\345\255\220\345\274\271", 0));
        grenadeCheckBox->setText(QApplication::translate("Widget", "\346\227\240\351\231\220\346\211\213\351\233\267\357\274\210\351\234\200\346\217\220\345\211\215\344\271\260\357\274\211", 0));
        recoilCheckBox->setText(QApplication::translate("Widget", "\346\227\240\345\220\216\345\235\220\345\212\233", 0));
        goCheckBox->setText(QApplication::translate("Widget", "\346\232\264\350\265\260\346\250\241\345\274\217", 0));
        statusLabel->setText(QApplication::translate("Widget", "\346\234\252\346\243\200\346\265\213\345\210\260\346\270\270\346\210\217\350\277\220\350\241\214...", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
