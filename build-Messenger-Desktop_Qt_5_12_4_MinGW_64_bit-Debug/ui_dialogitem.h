/********************************************************************************
** Form generated from reading UI file 'dialogitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGITEM_H
#define UI_DIALOGITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogItem
{
public:
    QLabel *title;
    QLabel *text;

    void setupUi(QWidget *DialogItem)
    {
        if (DialogItem->objectName().isEmpty())
            DialogItem->setObjectName(QString::fromUtf8("DialogItem"));
        DialogItem->resize(200, 80);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogItem->sizePolicy().hasHeightForWidth());
        DialogItem->setSizePolicy(sizePolicy);
        DialogItem->setMinimumSize(QSize(200, 80));
        DialogItem->setMaximumSize(QSize(200, 80));
        title = new QLabel(DialogItem);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(10, 10, 131, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        text = new QLabel(DialogItem);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(10, 45, 221, 21));

        retranslateUi(DialogItem);

        QMetaObject::connectSlotsByName(DialogItem);
    } // setupUi

    void retranslateUi(QWidget *DialogItem)
    {
        DialogItem->setWindowTitle(QApplication::translate("DialogItem", "Form", nullptr));
        title->setText(QApplication::translate("DialogItem", "UserName", nullptr));
        text->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogItem: public Ui_DialogItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGITEM_H
