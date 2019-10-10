#ifndef CHATLIST_H
#define CHATLIST_H

#include <QScrollArea>
class WidgetChatList;

namespace Chat {
	struct Dialog
	{
		QString title;
		QString text;
	};
}

class ChatList : public QScrollArea
{
	Q_OBJECT

public:
	ChatList(QWidget *parent = Q_NULLPTR);
	~ChatList() Q_DECL_OVERRIDE;

	Chat::Dialog currentDialog() const; // warning: check on empty title if dialog is not choose
	QList<Chat::Dialog> dialogs() const;
	void deleteDialog(const QString &title);


	void setBackgroundColor(const QColor &color);
	void setBackgroundHoverColor(const QColor &color);
	void setBackgroundReleaseColor(const QColor &color);

	void setTitleFont(const QFont &font);
	void setTitleColor(const QColor &color);

	void setTextFont(const QFont &font);
	void setTextColor(const QColor &color);

	bool isFound(const QString &str);

	void upNewMessage(const QString &title);
	void clearNewMessages(const QString &title);
	void setNewMessageColor(const QColor &color);
	void setNewMessageBackgroundColor(const QColor &color);

public slots:
	void appendDialog(const QString &title, const QString &text);

	void upDialog(const QString &title);
	void upDialog(const QString &title, const QString &newText);

	void changeTitle(const QString &title, const QString &newTitle);
	void changeText(const QString &title, const QString &newText);

	void hideDialog(const QString &title);
	void showDialog(const QString &title);
	void showDialogs();

private:
	WidgetChatList *mChatList;

	QString mCss;

protected:
	void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

signals:
	void clicked(const QString&);
	void deleted(const QString&);
};
#endif // CHATLIST_H
