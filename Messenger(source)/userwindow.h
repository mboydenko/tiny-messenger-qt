#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>

#include "user.h"

#include "chatbox.h"
#include "userbox.h"
#include "dialogsbox.h"

namespace Ui {
class UserWindow;

}

class UserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserWindow(const User &user, QWidget *parent = nullptr);
    ~UserWindow();


private:
    void addDialogToDialogList(const QString&);
    void setDialogTextToDialogList(const QString &title, const QString& message);
    void addMessageToChat(const QString& message, const QString& sender, const QString& destenation);
    void addMessageToChat(const QString&, const QString&);
    //void deleteDialog(const QString&);

public slots:
    void slotAddDialog(const QString&);
    void slotDeleteDialog(const QString&);
    void slotSelectDialog(const QString&);
    void slotAddMessage(const QString&, const QString &sender, const QString &destination);

private slots:
    void slotAddMessage(const QString&, const QString &);

signals:
    void signalDeleteDialog(const QString&);
    void signalAddDialog(const QString&);
    void signalSendMessage(const QString&, const QString&);

    void signalExit();
private:
    Ui::UserWindow *ui;

private:
    const User *mUser;

    ChatBox *mChatBoxWidget;
    UserBox *mUserBoxWidget;
    DialogsBox *mDialogBoxWidget;
};

#endif // USERWINDOW_H
