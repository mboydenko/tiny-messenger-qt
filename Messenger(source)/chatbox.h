#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include <QList>

#include "dialog.h"
#include "message.h"

#include "chatRegionWidget/chatregion.h"

namespace Ui {
class ChatBox;
}

class ChatBox : public QWidget
{
    Q_OBJECT

public:
    explicit ChatBox(QWidget *parent = nullptr);
    ~ChatBox();

public:
    void setDialog (Dialog *dialog);

    void addMessage (const QString& mes, const bool& ofCompanion);
    void addMessage(const Message*);

    QString getTitle() const;

    void removeDialog();

private:
    void setTitle(const QString&);
    void showChat();
    void hideChat();
    void loadDialog(Dialog *dialog);

signals:
    //Сообщает программе, что сообщение отправлено(Сообщение,кому)
    void sendMessage(const QString&, const QString&);

    void sendToClientDataBase(const QString&, const QString&);
    void sendToServerDataBase(const QString&, const QString&);

private slots:
    //Служит для отправки сообщений
    void sendMessage();


private:
    Ui::ChatBox *ui;

private:
    Dialog *mDialog{nullptr};
    ChatRegion *mChat;

	bool mChatIsShow;

	// QObject interface
public:
	bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;
};

#endif // CHATBOX_H
