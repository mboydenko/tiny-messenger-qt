/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

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

class Ui_Registration
{
public:
    QPushButton *registerButton;
    QLineEdit *passwordAgainEdit;
    QLineEdit *passwordEdit;
    QLineEdit *loginEdit;
    QLabel *label;
    QLabel *messageLable;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *authorizationButton;
    QPushButton *registrationButton;
    ButtonImage *settingsButton;

    void setupUi(QWidget *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QString::fromUtf8("Registration"));
        Registration->resize(640, 540);
        Registration->setMinimumSize(QSize(640, 540));
        Registration->setMaximumSize(QSize(640, 540));
        Registration->setAutoFillBackground(true);
        Registration->setStyleSheet(QString::fromUtf8(""));
        registerButton = new QPushButton(Registration);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(70, 420, 500, 50));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(registerButton->sizePolicy().hasHeightForWidth());
        registerButton->setSizePolicy(sizePolicy);
        registerButton->setMinimumSize(QSize(0, 50));
        registerButton->setMaximumSize(QSize(9999999, 9999999));
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        registerButton->setFont(font);
        registerButton->setCursor(QCursor(Qt::PointingHandCursor));
        registerButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        passwordAgainEdit = new QLineEdit(Registration);
        passwordAgainEdit->setObjectName(QString::fromUtf8("passwordAgainEdit"));
        passwordAgainEdit->setGeometry(QRect(45, 330, 550, 50));
        passwordAgainEdit->setMinimumSize(QSize(550, 50));
        passwordAgainEdit->setMaximumSize(QSize(608, 70));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nirmala UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStyleStrategy(QFont::PreferAntialias);
        passwordAgainEdit->setFont(font1);
        passwordAgainEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: rgb(44, 56, 68);\n"
"	border-style: solid;\n"
"	border-color: rgb(74, 87, 94);\n"
"	border-width: 2;\n"
"	border-radius: 5px;\n"
"	color: rgb(126,132,138)\n"
"}"));
        passwordAgainEdit->setEchoMode(QLineEdit::Password);
        passwordAgainEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        passwordAgainEdit->setDragEnabled(true);
        passwordEdit = new QLineEdit(Registration);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(45, 270, 550, 50));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(passwordEdit->sizePolicy().hasHeightForWidth());
        passwordEdit->setSizePolicy(sizePolicy1);
        passwordEdit->setMinimumSize(QSize(550, 50));
        passwordEdit->setMaximumSize(QSize(608, 70));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        font2.setStyleStrategy(QFont::PreferAntialias);
        passwordEdit->setFont(font2);
        passwordEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: rgb(44, 56, 68);\n"
"	border-style: solid;\n"
"	border-color: rgb(74, 87, 94);\n"
"	border-width: 2;\n"
"	border-radius: 5px;\n"
"	color: rgb(126,132,138)\n"
"}"));
        passwordEdit->setEchoMode(QLineEdit::Password);
        passwordEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        loginEdit = new QLineEdit(Registration);
        loginEdit->setObjectName(QString::fromUtf8("loginEdit"));
        loginEdit->setGeometry(QRect(45, 210, 550, 50));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(loginEdit->sizePolicy().hasHeightForWidth());
        loginEdit->setSizePolicy(sizePolicy2);
        loginEdit->setMinimumSize(QSize(550, 50));
        loginEdit->setMaximumSize(QSize(400, 70));
        loginEdit->setFont(font2);
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
"\n"
""));
        loginEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        loginEdit->setDragEnabled(false);
        loginEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        label = new QLabel(Registration);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 150, 600, 34));
        QFont font3;
        font3.setPointSize(17);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        label->setAlignment(Qt::AlignCenter);
        messageLable = new QLabel(Registration);
        messageLable->setObjectName(QString::fromUtf8("messageLable"));
        messageLable->setGeometry(QRect(80, 490, 480, 30));
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
        horizontalFrame = new QFrame(Registration);
        horizontalFrame->setObjectName(QString::fromUtf8("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(65, 50, 510, 80));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        authorizationButton = new QPushButton(horizontalFrame);
        authorizationButton->setObjectName(QString::fromUtf8("authorizationButton"));
        authorizationButton->setMinimumSize(QSize(245, 60));
        QFont font5;
        font5.setPointSize(12);
        authorizationButton->setFont(font5);
        authorizationButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(74, 87, 94);\n"
"border-radius: 0px;\n"
"color:white\n"
"}"));

        horizontalLayout->addWidget(authorizationButton);

        registrationButton = new QPushButton(horizontalFrame);
        registrationButton->setObjectName(QString::fromUtf8("registrationButton"));
        registrationButton->setMinimumSize(QSize(245, 60));
        registrationButton->setFont(font5);
        registrationButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(15, 91, 255);\n"
"border-radius: 0px;\n"
"color: white;\n"
"}"));

        horizontalLayout->addWidget(registrationButton);

        settingsButton = new ButtonImage(Registration);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));
        settingsButton->setGeometry(QRect(10, 10, 30, 30));
        QWidget::setTabOrder(loginEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, passwordAgainEdit);
        QWidget::setTabOrder(passwordAgainEdit, registerButton);
        QWidget::setTabOrder(registerButton, authorizationButton);
        QWidget::setTabOrder(authorizationButton, registrationButton);
        QWidget::setTabOrder(registrationButton, settingsButton);

        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QApplication::translate("Registration", "Form", nullptr));
        registerButton->setText(QApplication::translate("Registration", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        passwordAgainEdit->setText(QString());
        passwordAgainEdit->setPlaceholderText(QApplication::translate("Registration", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        passwordEdit->setPlaceholderText(QApplication::translate("Registration", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        loginEdit->setPlaceholderText(QApplication::translate("Registration", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label->setText(QApplication::translate("Registration", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        messageLable->setText(QString());
        authorizationButton->setText(QApplication::translate("Registration", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        registrationButton->setText(QApplication::translate("Registration", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        settingsButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
