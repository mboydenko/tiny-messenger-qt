/********************************************************************************
** Form generated from reading UI file 'authorization.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATION_H
#define UI_AUTHORIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "Other/buttonimage.h"

QT_BEGIN_NAMESPACE

class Ui_Authorization
{
public:
    QLineEdit *passwordEdit;
    QLineEdit *loginEdit;
    QLabel *label;
    QPushButton *loginButton;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *authorizationButton;
    QPushButton *registrationButton;
    QLabel *messageLable;
    ButtonImage *settingsButton;

    void setupUi(QWidget *Authorization)
    {
        if (Authorization->objectName().isEmpty())
            Authorization->setObjectName(QString::fromUtf8("Authorization"));
        Authorization->resize(640, 540);
        Authorization->setMinimumSize(QSize(640, 540));
        Authorization->setMaximumSize(QSize(640, 540));
        Authorization->setAutoFillBackground(false);
        Authorization->setStyleSheet(QString::fromUtf8(""));
        passwordEdit = new QLineEdit(Authorization);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(45, 280, 550, 50));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(passwordEdit->sizePolicy().hasHeightForWidth());
        passwordEdit->setSizePolicy(sizePolicy);
        passwordEdit->setMinimumSize(QSize(550, 50));
        passwordEdit->setMaximumSize(QSize(608, 70));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        passwordEdit->setFont(font);
        passwordEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: rgb(44, 56, 68);\n"
"	border-style: solid;\n"
"	border-color: rgb(74, 87, 94);\n"
"	border-width: 2;\n"
"	border-radius: 5px;\n"
"	color: rgb(126,132,138)\n"
"}\n"
""));
        passwordEdit->setEchoMode(QLineEdit::Password);
        passwordEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        loginEdit = new QLineEdit(Authorization);
        loginEdit->setObjectName(QString::fromUtf8("loginEdit"));
        loginEdit->setGeometry(QRect(45, 220, 550, 50));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loginEdit->sizePolicy().hasHeightForWidth());
        loginEdit->setSizePolicy(sizePolicy1);
        loginEdit->setMinimumSize(QSize(550, 50));
        loginEdit->setMaximumSize(QSize(400, 70));
        loginEdit->setFont(font);
        loginEdit->setContextMenuPolicy(Qt::DefaultContextMenu);
        loginEdit->setLayoutDirection(Qt::LeftToRight);
        loginEdit->setAutoFillBackground(false);
        loginEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: rgb(44, 56, 68);\n"
"	border-style: solid;\n"
"	border-color: rgb(74, 87, 94);\n"
"	border-width: 2;\n"
"	border-radius: 5px;\n"
"	color: rgb(126,132,138)\n"
"}\n"
""));
        loginEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        loginEdit->setDragEnabled(false);
        loginEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        label = new QLabel(Authorization);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 150, 600, 34));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color:white"));
        label->setAlignment(Qt::AlignCenter);
        loginButton = new QPushButton(Authorization);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(65, 360, 500, 50));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy2);
        loginButton->setMinimumSize(QSize(0, 50));
        loginButton->setMaximumSize(QSize(9999999, 9999999));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nirmala UI"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        loginButton->setFont(font2);
        loginButton->setCursor(QCursor(Qt::PointingHandCursor));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(15, 91, 255);\n"
"	border-radius: 7px;\n"
"	color:white\n"
"}\n"
"\n"
"QPushButton::Pressed\n"
"{\n"
"background-color: rgb(74, 87, 94);\n"
"border-radius: 7px;\n"
"color:white\n"
"}\n"
"\n"
"QPushButton::Released\n"
"{\n"
"	background-color: rgb(15, 91, 255);\n"
"	border-radius: 7px;	\n"
"	color:white\n"
"}"));
        horizontalFrame = new QFrame(Authorization);
        horizontalFrame->setObjectName(QString::fromUtf8("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(65, 50, 510, 80));
        horizontalFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border-style:solid;\n"
"	border-width:0px;\n"
"	border-radius:0px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        authorizationButton = new QPushButton(horizontalFrame);
        authorizationButton->setObjectName(QString::fromUtf8("authorizationButton"));
        authorizationButton->setMinimumSize(QSize(245, 60));
        QFont font3;
        font3.setPointSize(12);
        authorizationButton->setFont(font3);
        authorizationButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(15, 91, 255);\n"
"	border-radius: 0px;\n"
"color: white;\n"
"}"));

        horizontalLayout->addWidget(authorizationButton);

        registrationButton = new QPushButton(horizontalFrame);
        registrationButton->setObjectName(QString::fromUtf8("registrationButton"));
        registrationButton->setMinimumSize(QSize(245, 60));
        registrationButton->setFont(font3);
        registrationButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(74, 87, 94);\n"
"border-radius: 0px;\n"
"color: white;\n"
"}"));

        horizontalLayout->addWidget(registrationButton);

        messageLable = new QLabel(Authorization);
        messageLable->setObjectName(QString::fromUtf8("messageLable"));
        messageLable->setGeometry(QRect(100, 440, 480, 30));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(messageLable->sizePolicy().hasHeightForWidth());
        messageLable->setSizePolicy(sizePolicy3);
        messageLable->setMinimumSize(QSize(0, 30));
        messageLable->setMaximumSize(QSize(608, 50));
        QFont font4;
        font4.setPointSize(10);
        messageLable->setFont(font4);
        messageLable->setStyleSheet(QString::fromUtf8(""));
        messageLable->setAlignment(Qt::AlignCenter);
        settingsButton = new ButtonImage(Authorization);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));
        settingsButton->setGeometry(QRect(10, 10, 30, 30));
        settingsButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(15, 91, 255);\n"
"	border-radius: 7px;\n"
"	color:white\n"
"}\n"
"\n"
"QPushButton::Pressed\n"
"{\n"
"background-color: rgb(25,68,84);\n"
"border-radius: 7px;\n"
"color:white\n"
"}\n"
"\n"
"QPushButton::Released\n"
"{\n"
"	background-color: rgb(15, 91, 255);\n"
"	border-radius: 7px;	\n"
"	color:white\n"
"}"));
        QWidget::setTabOrder(loginEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, loginButton);
        QWidget::setTabOrder(loginButton, authorizationButton);
        QWidget::setTabOrder(authorizationButton, registrationButton);
        QWidget::setTabOrder(registrationButton, settingsButton);

        retranslateUi(Authorization);

        QMetaObject::connectSlotsByName(Authorization);
    } // setupUi

    void retranslateUi(QWidget *Authorization)
    {
        Authorization->setWindowTitle(QApplication::translate("Authorization", "Form", nullptr));
        passwordEdit->setPlaceholderText(QApplication::translate("Authorization", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        loginEdit->setPlaceholderText(QApplication::translate("Authorization", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label->setText(QApplication::translate("Authorization", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        loginButton->setText(QApplication::translate("Authorization", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        authorizationButton->setText(QApplication::translate("Authorization", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        registrationButton->setText(QApplication::translate("Authorization", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        messageLable->setText(QString());
        settingsButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Authorization: public Ui_Authorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATION_H
