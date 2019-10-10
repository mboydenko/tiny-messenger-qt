/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "chatbox.h"
#include "dialogsbox.h"
#include "userbox.h"

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    UserBox *userBox;
    DialogsBox *dialogsBox;
    ChatBox *chatBox;

    void setupUi(QWidget *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
        UserWindow->resize(948, 603);
        UserWindow->setAutoFillBackground(false);
        UserWindow->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(UserWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        userBox = new UserBox(UserWindow);
        userBox->setObjectName(QString::fromUtf8("userBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userBox->sizePolicy().hasHeightForWidth());
        userBox->setSizePolicy(sizePolicy);
        userBox->setMinimumSize(QSize(240, 70));
        userBox->setAutoFillBackground(true);
        userBox->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(userBox);

        dialogsBox = new DialogsBox(UserWindow);
        dialogsBox->setObjectName(QString::fromUtf8("dialogsBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dialogsBox->sizePolicy().hasHeightForWidth());
        dialogsBox->setSizePolicy(sizePolicy1);
        dialogsBox->setMinimumSize(QSize(240, 0));
        dialogsBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(dialogsBox);


        horizontalLayout->addLayout(verticalLayout);

        chatBox = new ChatBox(UserWindow);
        chatBox->setObjectName(QString::fromUtf8("chatBox"));
        chatBox->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(chatBox);


        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QWidget *UserWindow)
    {
        UserWindow->setWindowTitle(QApplication::translate("UserWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
