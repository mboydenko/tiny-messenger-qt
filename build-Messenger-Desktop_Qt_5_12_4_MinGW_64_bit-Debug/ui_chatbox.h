/********************************************************************************
** Form generated from reading UI file 'chatbox.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOX_H
#define UI_CHATBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatBox
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *title;
    QGridLayout *chatLayout;
    QWidget *textInputWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textInput;
    QPushButton *sendButton;

    void setupUi(QWidget *ChatBox)
    {
        if (ChatBox->objectName().isEmpty())
            ChatBox->setObjectName(QString::fromUtf8("ChatBox"));
        ChatBox->resize(608, 679);
        verticalLayout = new QVBoxLayout(ChatBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 0, 0, 0);
        titleWidget = new QWidget(ChatBox);
        titleWidget->setObjectName(QString::fromUtf8("titleWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleWidget->sizePolicy().hasHeightForWidth());
        titleWidget->setSizePolicy(sizePolicy);
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(titleWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        title = new QLabel(titleWidget);
        title->setObjectName(QString::fromUtf8("title"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy1);
        title->setMinimumSize(QSize(606, 40));
        title->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("background-color: rgb(55, 71, 87);\n"
"color: rgb(250, 250, 250);"));
        title->setMargin(8);

        horizontalLayout_2->addWidget(title);


        verticalLayout->addWidget(titleWidget);

        chatLayout = new QGridLayout();
        chatLayout->setSpacing(0);
        chatLayout->setObjectName(QString::fromUtf8("chatLayout"));

        verticalLayout->addLayout(chatLayout);

        textInputWidget = new QWidget(ChatBox);
        textInputWidget->setObjectName(QString::fromUtf8("textInputWidget"));
        sizePolicy.setHeightForWidth(textInputWidget->sizePolicy().hasHeightForWidth());
        textInputWidget->setSizePolicy(sizePolicy);
        textInputWidget->setMinimumSize(QSize(0, 50));
        textInputWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(textInputWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textInput = new QTextEdit(textInputWidget);
        textInput->setObjectName(QString::fromUtf8("textInput"));
        textInput->setMinimumSize(QSize(0, 50));
        textInput->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setPointSize(13);
        textInput->setFont(font1);
        textInput->setStyleSheet(QString::fromUtf8("background-color: rgb(55, 71, 87);\n"
"color: rgb(250, 250, 250);"));
        textInput->setFrameShape(QFrame::NoFrame);

        horizontalLayout->addWidget(textInput);

        sendButton = new QPushButton(textInputWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(50);
        sizePolicy2.setVerticalStretch(50);
        sizePolicy2.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy2);
        sendButton->setMinimumSize(QSize(50, 50));
        sendButton->setMaximumSize(QSize(50, 50));
        sendButton->setFont(font);
        sendButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(15, 91, 255);\n"
"	border-radius: 0px;\n"
"	color:white\n"
"}\n"
"\n"
"QPushButton::Pressed\n"
"{\n"
"background-color: rgb(25,68,84);\n"
"border-radius: 0px;\n"
"color:white\n"
"}\n"
"\n"
"QPushButton::Released\n"
"{\n"
"	background-color: rgb(15, 91, 255);\n"
"	border-radius: 7px;	\n"
"	color:white\n"
"}"));

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addWidget(textInputWidget);


        retranslateUi(ChatBox);

        QMetaObject::connectSlotsByName(ChatBox);
    } // setupUi

    void retranslateUi(QWidget *ChatBox)
    {
        ChatBox->setWindowTitle(QApplication::translate("ChatBox", "Form", nullptr));
        title->setText(QApplication::translate("ChatBox", "ChatName", nullptr));
        textInput->setPlaceholderText(QApplication::translate("ChatBox", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        sendButton->setText(QApplication::translate("ChatBox", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatBox: public Ui_ChatBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOX_H
