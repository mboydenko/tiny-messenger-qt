#include "addnewdialogwindow.h"
#include "ui_addnewdialogwindow.h"


#include <QDebug>

AddNewDialogWindow::AddNewDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDialogWindow)
{
    ui->setupUi(this);

	setWindowTitle("Add new dialog");
}

AddNewDialogWindow::~AddNewDialogWindow()
{
    delete ui;
}

void AddNewDialogWindow::setErrorStyleSheet()
{
    ui->label->setStyleSheet("color:red");
}


void AddNewDialogWindow::userNotFound()
{
    setErrorStyleSheet();
    ui->label->setText("Пользватель не найден");
    qDebug() << "Пользватель не найден";
}

void AddNewDialogWindow::dialogAlreadyExists()
{
    setErrorStyleSheet();
    qDebug() << "Диалог уже существует";
}

void AddNewDialogWindow::serverNotAvailable()
{
    setErrorStyleSheet();
    ui->label->setText("Сервер не доступен");
}

void AddNewDialogWindow::on_addButton_clicked()
{
    emit signalAddDialog(ui->lineEdit->text());
}

void AddNewDialogWindow::dialogAdded(const QString &dialog)
{
    if(dialog == ui->lineEdit->text())
        close();
}

void AddNewDialogWindow::on_lineEdit_textEdited(const QString &)
{
    ui->label->setText("");
}
