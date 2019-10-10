#include "chatlist.h"
#include "widgetchatlist.h"
#include <QResizeEvent>
#include <QFile>
#include <QDebug>

ChatList::ChatList(QWidget *parent)
	: QScrollArea(parent)
{
	mChatList = new WidgetChatList(this);

	connect(mChatList, SIGNAL(clicked(const QString&)),
			this, SIGNAL(clicked(const QString&)));
	connect(mChatList, SIGNAL(deleted(const QString&)),
			this, SIGNAL(deleted(const QString&)));

	setWidget(mChatList);

	setAutoFillBackground(true);
	QPalette pal = palette();
	pal.setColor(QPalette::Background, QColor(250, 250, 250));
	setPalette(pal);

	QFile file("Qss/QScrollArea.css");
	if (!file.open(QIODevice::ReadOnly)) qDebug() << file.errorString();
	else mCss = file.readAll();

	setStyleSheet(mCss);

	//setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
}

ChatList::~ChatList()
{

}

Chat::Dialog ChatList::currentDialog() const
{
	return Chat::Dialog { mChatList->currentDialogTitle(), mChatList->currentDialogText() };
}

QList<Chat::Dialog> ChatList::dialogs() const
{
	QList<Chat::Dialog> list;
	for (int i = 0; i < mChatList->countBlocks(); i++)
		list.append(Chat::Dialog { mChatList->dialogTitle(i), mChatList->dialogText(i) });

	return list;
}

void ChatList::deleteDialog(const QString &title)
{
	mChatList->deleteBlock(title);
}

void ChatList::appendDialog(const QString &title, const QString &text)
{
	mChatList->appendBlock(title, text);
}

void ChatList::upDialog(const QString &title)
{
	mChatList->upBlock(title);
}

void ChatList::upDialog(const QString &title, const QString &newText)
{
	mChatList->changeText(title, newText);
	mChatList->upBlock(title);
}

void ChatList::changeTitle(const QString &title, const QString &newTitle)
{
	mChatList->changeTitle(title, newTitle);
}

void ChatList::changeText(const QString &title, const QString &newText)
{
	mChatList->changeText(title, newText);
}

void ChatList::hideDialog(const QString &title)
{
	mChatList->hideBlock(title);
}

void ChatList::showDialog(const QString &title)
{
	mChatList->showBlock(title);
}

void ChatList::showDialogs()
{
	mChatList->showBlocks();
}

void ChatList::setBackgroundColor(const QColor &color)
{
	QPalette pal = palette();
	pal.setColor(QPalette::Background, color);
	setPalette(pal);

	setStyleSheet("QScrollArea { background-color: rgb(" +
				  QString::number(color.red()) +  ", " +
				  QString::number(color.green()) + ", " +
				  QString::number(color.blue()) +"); }" +
				  mCss);

	mChatList->setBackgroundColor(color);
}

void ChatList::setBackgroundHoverColor(const QColor &color)
{
	mChatList->setBackgroundHoverColor(color);
}

void ChatList::setBackgroundReleaseColor(const QColor &color)
{
	mChatList->setBackgroundReleaseColor(color);
}

void ChatList::setTitleFont(const QFont &font)
{
	mChatList->setTitleFont(font);
}

void ChatList::setTitleColor(const QColor &color)
{
	mChatList->setTitleColor(color);
}

void ChatList::setTextFont(const QFont &font)
{
	mChatList->setTextFont(font);
}

void ChatList::setTextColor(const QColor &color)
{
	mChatList->setTextColor(color);
}

bool ChatList::isFound(const QString &str)
{
	return mChatList->isFound(str);
}

void ChatList::resizeEvent(QResizeEvent *event)
{
	if (event->size().width() != event->oldSize().width())
		mChatList->parentResized(event->size());

	QScrollArea::resizeEvent(event);
}

void ChatList::upNewMessage(const QString &title)
{
	mChatList->upNewMessage(title);
}
void ChatList::clearNewMessages(const QString &title)
{
	mChatList->clearNewMessages(title);
}
void ChatList::setNewMessageColor(const QColor &color)
{
	mChatList->setNewMessageColor(color);
}

void ChatList::setNewMessageBackgroundColor(const QColor &color)
{
	mChatList->setNewMessageBackgroundColor(color);
}
