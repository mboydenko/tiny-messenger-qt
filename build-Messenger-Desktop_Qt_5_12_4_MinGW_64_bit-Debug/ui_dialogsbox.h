/********************************************************************************
** Form generated from reading UI file 'dialogsbox.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSBOX_H
#define UI_DIALOGSBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogsBox
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *searchLineEdit;
    QVBoxLayout *layoutForDialogList;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *DialogsBox)
    {
        if (DialogsBox->objectName().isEmpty())
            DialogsBox->setObjectName(QString::fromUtf8("DialogsBox"));
        DialogsBox->resize(240, 636);
        DialogsBox->setMaximumSize(QSize(240, 16777215));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(44, 56, 68, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(34, 99, 88, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(28, 82, 73, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(11, 33, 29, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(15, 44, 39, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        QBrush brush9(QColor(23, 66, 59, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        DialogsBox->setPalette(palette);
        verticalLayout_2 = new QVBoxLayout(DialogsBox);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(DialogsBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(240, 0));
        widget_2->setToolTipDuration(-1);
        widget_2->setStyleSheet(QString::fromUtf8("background-color:rgb(55, 71, 87);\n"
""));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(11, 5, 11, 5);
        searchLineEdit = new QLineEdit(widget_2);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));
        searchLineEdit->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        searchLineEdit->setFont(font);
        searchLineEdit->setFocusPolicy(Qt::StrongFocus);
        searchLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 56, 68);\n"
"color: rgb(200, 200, 200);\n"
"border-radius:5;\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-color: rgb(24, 37, 51);"));
        searchLineEdit->setFrame(true);

        verticalLayout->addWidget(searchLineEdit);


        verticalLayout_2->addWidget(widget_2);

        layoutForDialogList = new QVBoxLayout();
        layoutForDialogList->setObjectName(QString::fromUtf8("layoutForDialogList"));

        verticalLayout_2->addLayout(layoutForDialogList);

        widget = new QWidget(DialogsBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(240, 50));
        widget->setMaximumSize(QSize(16777215, 50));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(55, 71, 87);\n"
""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 11, 0, 11);
        addButton = new QPushButton(widget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        addButton->setMinimumSize(QSize(100, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStyleStrategy(QFont::PreferDefault);
        addButton->setFont(font1);
        addButton->setFocusPolicy(Qt::TabFocus);
        addButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(44, 56, 68);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-color: rgb(24, 37, 51);\n"
"border-radius: 5;\n"
"color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(25,68,84);border-style: outset;\n"
"border-width: 2px;border-color: rgb(24, 37, 51);\n"
"color: white;\n"
"}\n"
"\n"
"QPushButton:released {\n"
"background-color: black;border-style: outset;\n"
"border-width: 2px;border-color: black;\n"
"color: white;\n"
"}"));

        horizontalLayout->addWidget(addButton);

        deleteButton = new QPushButton(widget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);
        deleteButton->setMinimumSize(QSize(100, 30));
        deleteButton->setFont(font);
        deleteButton->setFocusPolicy(Qt::TabFocus);
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(44, 56, 68);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-color: rgb(24, 37, 51);\n"
"border-radius: 5;\n"
"color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(25,68,84);border-style: outset;\n"
"border-width: 2px;border-color: rgb(24, 37, 51);\n"
"color: white;\n"
"}\n"
"\n"
"QPushButton:released {\n"
"background-color: black;border-style: outset;\n"
"border-width: 2px;border-color: black;\n"
"color: white;\n"
"}"));

        horizontalLayout->addWidget(deleteButton);


        verticalLayout_2->addWidget(widget);


        retranslateUi(DialogsBox);

        QMetaObject::connectSlotsByName(DialogsBox);
    } // setupUi

    void retranslateUi(QWidget *DialogsBox)
    {
        DialogsBox->setWindowTitle(QApplication::translate("DialogsBox", "Form", nullptr));
        searchLineEdit->setPlaceholderText(QApplication::translate("DialogsBox", "\320\237\320\276\320\270\321\201\320\272...", nullptr));
        addButton->setText(QApplication::translate("DialogsBox", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteButton->setText(QApplication::translate("DialogsBox", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogsBox: public Ui_DialogsBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSBOX_H
