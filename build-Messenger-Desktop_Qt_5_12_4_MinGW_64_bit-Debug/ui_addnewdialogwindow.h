/********************************************************************************
** Form generated from reading UI file 'addnewdialogwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWDIALOGWINDOW_H
#define UI_ADDNEWDIALOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddNewDialogWindow
{
public:
    QPushButton *addButton;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *AddNewDialogWindow)
    {
        if (AddNewDialogWindow->objectName().isEmpty())
            AddNewDialogWindow->setObjectName(QString::fromUtf8("AddNewDialogWindow"));
        AddNewDialogWindow->resize(400, 210);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddNewDialogWindow->sizePolicy().hasHeightForWidth());
        AddNewDialogWindow->setSizePolicy(sizePolicy);
        AddNewDialogWindow->setMinimumSize(QSize(400, 210));
        AddNewDialogWindow->setMaximumSize(QSize(400, 210));
        AddNewDialogWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 56, 68);"));
        addButton = new QPushButton(AddNewDialogWindow);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(50, 100, 301, 41));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        addButton->setFont(font);
        addButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(30, 42, 53);\n"
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
        lineEdit = new QLineEdit(AddNewDialogWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 30, 341, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Yu Gothic UI"));
        font1.setPointSize(14);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: rgb(44, 56, 68);\n"
"	border-style: solid;\n"
"	border-color: rgb(74, 87, 94);\n"
"	border-width: 2;\n"
"	border-radius: 5px;\n"
"	color: rgb(126,132,138)\n"
"}\n"
""));
        lineEdit->setAlignment(Qt::AlignCenter);
        label = new QLabel(AddNewDialogWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 150, 331, 41));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(AddNewDialogWindow);

        QMetaObject::connectSlotsByName(AddNewDialogWindow);
    } // setupUi

    void retranslateUi(QDialog *AddNewDialogWindow)
    {
        AddNewDialogWindow->setWindowTitle(QApplication::translate("AddNewDialogWindow", "Dialog", nullptr));
        addButton->setText(QApplication::translate("AddNewDialogWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("AddNewDialogWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddNewDialogWindow: public Ui_AddNewDialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWDIALOGWINDOW_H
