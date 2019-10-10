#include "chatblock.h"
#include "chatregion.h"
#include "chatregion_scene.h"
#include <QResizeEvent>
#include <QScrollBar>
#include <QFile>
#include <QDebug>

ChatRegion::ChatRegion(QWidget *parent)
	: QGraphicsView(parent)
{
	// Начальные значения окна
    resize(300, 300);

	mScene = new ChatRegion_Scene(size(), this);
	connect(this, SIGNAL(resized(const QSize&)),
			mScene, SLOT(parentResized(const QSize&)));
	setScene(mScene);

	QFile file("Qss/QScrollArea.css");
	if (!file.open(QIODevice::ReadOnly)) qDebug() << file.errorString();
	else mCss = file.readAll();

	setStyleSheet(mCss);

    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

ChatRegion::~ChatRegion()
{
	delete mScene;
}

void ChatRegion::setFont(const QFont &font)
{
	mScene->setFont(font);
}

void ChatRegion::setBackgroundColor(const QColor &color)
{
	mScene->setBackgroundColor(color);
}

void ChatRegion::setUserColor(const QColor &text, const QColor &background)
{
	mScene->setUserColor(text, background);
}

void ChatRegion::setCompanionColor(const QColor &text, const QColor &background)
{
	mScene->setCompanionColor(text, background);
}

QList<Chat::Block> ChatRegion::getMessages() const
{
	QList<Chat::Block> list;
	for (int i = 0; i < mScene->countBlocks(); i++) {
		const ChatBlock* cBlock = mScene->getBlock(i);
		Chat::Block block;
		block.isUser = cBlock->typeMessage() == ChatBlock::User ? true :
																  false;
		block.message = cBlock->message();
		list.prepend(block);
	}
	return list;
}

void ChatRegion::loadChat(const QList<Chat::Block> &list)
{
	foreach (Chat::Block block, list) {
		mScene->appendBlock(block.message, block.isUser);
	}
}

void ChatRegion::clearChat()
{
	mScene->deleteBlocks();
}

void ChatRegion::appendBlock(const QString &message, const bool &isUser)
{
    mScene->appendBlock(message, isUser);
	verticalScrollBar()->setValue(verticalScrollBar()->maximum());
}

void ChatRegion::resizeEvent(QResizeEvent *event)
{
	emit resized(event->size());

	QGraphicsView::resizeEvent(event);
}

