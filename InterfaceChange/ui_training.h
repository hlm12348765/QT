/********************************************************************************
** Form generated from reading UI file 'training.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINING_H
#define UI_TRAINING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Training
{
public:
    QLabel *label;

    void setupUi(QWidget *Training)
    {
        if (Training->objectName().isEmpty())
            Training->setObjectName(QString::fromUtf8("Training"));
        Training->resize(520, 300);
        label = new QLabel(Training);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 120, 120, 17));

        retranslateUi(Training);

        QMetaObject::connectSlotsByName(Training);
    } // setupUi

    void retranslateUi(QWidget *Training)
    {
        Training->setWindowTitle(QApplication::translate("Training", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Training", "Training Started!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Training: public Ui_Training {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINING_H
