/********************************************************************************
** Form generated from reading UI file 'startup.ui'
**
** Created: Sat Oct 14 15:59:53 2017
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUP_H
#define UI_STARTUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startup
{
public:
    QLabel *label_2;
    QLabel *label;
    QProgressBar *bar1;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QPushButton *button2;

    void setupUi(QWidget *startup)
    {
        if (startup->objectName().isEmpty())
            startup->setObjectName(QString::fromUtf8("startup"));
        startup->resize(800, 480);
        label_2 = new QLabel(startup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 170, 780, 121));
        label = new QLabel(startup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -20, 800, 160));
        bar1 = new QProgressBar(startup);
        bar1->setObjectName(QString::fromUtf8("bar1"));
        bar1->setGeometry(QRect(20, 340, 760, 30));
        bar1->setValue(24);
        widget = new QWidget(startup);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 409, 761, 47));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        button2 = new QPushButton(widget);
        button2->setObjectName(QString::fromUtf8("button2"));

        horizontalLayout->addWidget(button2);


        retranslateUi(startup);

        QMetaObject::connectSlotsByName(startup);
    } // setupUi

    void retranslateUi(QWidget *startup)
    {
        startup->setWindowTitle(QApplication::translate("startup", "startup", 0, QApplication::UnicodeUTF8));
        startup->setProperty("qq", QVariant(QString()));
        label_2->setText(QApplication::translate("startup", "<html><head/><body><p align=\"center\"><span style=\" font-size:72pt;\">\346\234\272\345\212\250\350\275\246\351\251\276\351\251\266\344\272\272\345\234\272\345\234\260\351\251\276\351\251\266\346\212\200\350\203\275\350\200\203\350\257\225\357\274\210\347\247\221\347\233\256\344\272\214\357\274\211</span></p><p align=\"center\"><span style=\" font-size:72pt;\">\347\273\237\344\270\200\350\257\204\345\210\244\347\273\210\347\253\257</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("startup", "<html><head/><body><p><img src=\":/qrc/logo.png\"/></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("startup", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt;\">\345\210\235\345\247\213\345\214\226\347\212\266\346\200\201</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        button2->setText(QApplication::translate("startup", "\346\255\243\345\234\250\351\242\204\345\256\211\350\243\205,\350\257\267\347\255\211\345\276\205", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class startup: public Ui_startup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUP_H
