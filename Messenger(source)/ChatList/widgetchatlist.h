#ifndef WIDGETCHATLIST_H
#define WIDGETCHATLIST_H

#include <QFrame>

class ChatListBlock;


// Виджет хранящий список диалогов и работающий с ним
class WidgetChatList : public QFrame
{
	Q_OBJECT
public:
	explicit WidgetChatList(QWidget *parent = Q_NULLPTR);
	~WidgetChatList() Q_DECL_OVERRIDE;

	void appendBlock(const QString &title,
					 const QString &text);

    void upBlock(const int& index);
	void upBlock(const QString &title);

	void changeTitle(const QString &title, const QString &newTitle);

    void changeText(const int& index, const QString &newText);
	void changeText(const QString &title, const QString &newText);
    void deleteBlock(const int& index);
	void deleteBlock(const QString &title);
    void hideBlock(const int& index);
	void hideBlock(const QString &title);
    void showBlock(const int& index);
	void showBlock(const QString &title);
	void showBlocks();

	void setBackgroundColor(const QColor &color);
	void setBackgroundHoverColor(const QColor &color);
	void setBackgroundReleaseColor(const QColor &color);

	void setTitleFont(const QFont &font);
	void setTitleColor(const QColor &color);

	void setTextFont(const QFont &font);
	void setTextColor(const QColor &color);

	int countBlocks() const;

    bool blockIsHided(const QString&) const;
    bool blockIsHided(const int&) const;

	QString currentDialogTitle() const;
	QString currentDialogText() const;

	QString dialogTitle(const int&) const;
	QString dialogText(const int&) const;

    bool isFound(const QString&);

	void setNewMessageColor(const QColor &color);
	void setNewMessageBackgroundColor(const QColor &color);
	void upNewMessage(const QString &title);
	void clearNewMessages(const QString &title);

private:
	QFont  mTitleFont;
	QFont  mTextFont;
	QColor mTitleColor;
	QColor mTextColor;

	QColor mBackgroundColor;
	QColor mBackgroundHoverColor;
	QColor mBackgroundReleaseColor;

	QList<ChatListBlock*> mListBlocks;
	ChatListBlock *mBlockLastClicked; // default: nullptr

	QColor mNewMessageColor;
	QColor mNewMessageBackgroundColor;

public slots:
	void parentResized(const QSize &newSize);

private slots:
	void blockWasClicked();

signals:
	void clicked(const QString&); // return title
	void deleted(const QString&);
};

#endif // WIDGETCHATLIST_H
