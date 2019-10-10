#include "userwindow.h"
#include "ui_userwindow.h"

#include <QDebug>


UserWindow::UserWindow(const User &user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);

    mUser = &user;

    mUserBoxWidget   = ui->userBox;
    mDialogBoxWidget = ui->dialogsBox;
    mChatBoxWidget   = ui->chatBox;


    mUserBoxWidget->setUser(mUser->Name());
    mDialogBoxWidget->loadDialogs(mUser->dialogsList());

    //////////////////////////////////////////////////////////////////////////////////////////

    Q_ASSERT(QObject::connect
            (
                mUserBoxWidget,     SIGNAL(signalExit()),
                this,               SIGNAL(signalExit()))
            );

    Q_ASSERT(QObject::connect
             (
                 mChatBoxWidget,    SIGNAL(sendMessage(const QString&, const QString&)),
                 this,              SLOT(slotAddMessage(const QString&, const QString&)))
             );

    Q_ASSERT(QObject::connect
             (
                 mDialogBoxWidget,  SIGNAL(signalDialogSelected(const QString&)),
                 this,              SLOT(slotSelectDialog(const QString&)))
             );

    Q_ASSERT(QObject::connect(
                 mDialogBoxWidget,  SIGNAL(signalDeleteDialog(const QString&)),
                 this,              SLOT(slotDeleteDialog(const QString&)))
             );

    //////////////////////////////////////////////////////////////////////////////////////////

    setObjectName("UserWindow");


    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(44, 56, 68));
    setAutoFillBackground(true);
    setPalette(p);
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::setDialogTextToDialogList(const QString &title, const QString &message)
{
    mDialogBoxWidget->setMessageToDialog(title,message);
}

void UserWindow::slotAddDialog(const QString &dialog)
{
    mDialogBoxWidget->addDialog(dialog,"");
}

void UserWindow::slotDeleteDialog(const QString &dialog)
{
    if(mDialogBoxWidget == reinterpret_cast<DialogsBox*>(sender()))
    {
        mChatBoxWidget->removeDialog();
        emit signalDeleteDialog(dialog);
    }
    else
    {

        if(mChatBoxWidget->getTitle() == dialog)
        {
            mChatBoxWidget->removeDialog();
        }

        if(mDialogBoxWidget->isFound(dialog))
        {
            mDialogBoxWidget->deleteDialog(dialog);
        }
    }
}

void UserWindow::slotSelectDialog(const QString &dialog)
{
    Dialog *_dialog = mUser->getDialog(dialog);
    mChatBoxWidget->setDialog(_dialog);
}

void UserWindow::slotAddMessage(const QString &message, const QString &sender ,const QString& destination)
{
    if(mUser->Name() == sender)
    {
        QString mes = "Вы: " + message;
        setDialogTextToDialogList(destination,mes);

        if(mChatBoxWidget->getTitle() == destination)
        {
            mChatBoxWidget->addMessage(message,true);
        }
    }
    else if(mUser->Name() == destination)
    {
        setDialogTextToDialogList(sender,message);

        if(mChatBoxWidget->getTitle() == sender)
        {
            mChatBoxWidget->addMessage(message,false);
        }
    }
}

void UserWindow::slotAddMessage(const QString &mes, const QString &title)
{
    QString message = "Вы: " + mes;
    setDialogTextToDialogList(title,message);
    emit signalSendMessage(mes,title);
}

