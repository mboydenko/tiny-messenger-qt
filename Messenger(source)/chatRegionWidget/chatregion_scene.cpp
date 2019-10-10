#include "chatregion_scene.h"
#include "chatblock.h"
#include <QGraphicsRectItem>

ChatRegion_Scene::ChatRegion_Scene(const QSize &sizeParent, QObject *parent)
	: QGraphicsScene(parent)
{
	mStartHeight = sizeParent.width();
    mSizeWindow = sizeParent;
	setSceneRect(QRectF(0, 0, sizeParent.width(), sizeParent.height()));

	mRectBackground = new QGraphicsRectItem(QRectF(0, 0, sizeParent.width(), sizeParent.height()));
	mRectBackground->setBrush(QBrush(QColor(0, 0, 0)));
	mRectBackground->setPen(Qt::NoPen);
	addItem(mRectBackground);

	// Default colors
	mUserTextColor = QColor("#000000");
	mUserBackgroundColor = QColor(138, 209, 227);
	mCompanionTextColor = QColor("#000000");
	mCompanionBackgroundColor = QColor(150, 180, 250);
}

ChatRegion_Scene::~ChatRegion_Scene()
{
	deleteBlocks();

	delete mRectBackground;
}

void ChatRegion_Scene::appendBlock(const QString &message, const bool &isUser)
{
	ChatBlock *chatBlock = new ChatBlock(mSizeWindow.width(),
										 message,
										 isUser ? ChatBlock::User : ChatBlock::Companion,
										 mFont,
										 mUserTextColor,
										 mUserBackgroundColor,
										 mCompanionTextColor,
										 mCompanionBackgroundColor);

	// Добавление блока в чат
	int between = 5; /*разница между блоками*/

	// Вычисление нужной высоты для сцены
	qreal heightForScene = 0;
	heightForScene += chatBlock->height() + between;
	foreach (ChatBlock *block, mListBlocks) {
		heightForScene += block->height() + between;
	}
	// Если высота для чата больше начальной
	if (mStartHeight == 0 || heightForScene > mStartHeight) {
		// Изменяем высоту (блоки смещать больше не придется)
		setSceneRect(0, 0, sceneRect().width(), heightForScene);
		// Перемещение всех блоков выше
		if (mStartHeight != 0) {
			qreal yPos = 0;
			for (int i = mListBlocks.size() - 1; i >= 0; i--) {
				ChatBlock *buf_block = mListBlocks[i];
				buf_block->setPos(buf_block->x(), yPos);
				yPos += buf_block->height() + between;
			}
			mStartHeight = 0;
		}
	}
	// Иначе если высота для чата меньше изначальной
	else {
		// Перемещение всех блоков выше
		foreach (ChatBlock *block, mListBlocks) {
			ChatBlock *buf_block = block;
			buf_block->setPos(buf_block->x(),
							  buf_block->y() - chatBlock->height() - between);
		}
	}

	// Установка нужной позиции для блока
	if (chatBlock->typeMessage() == ChatBlock::User)
		chatBlock->setPos(sceneRect().width() - chatBlock->width(),
						  sceneRect().height() - chatBlock->height() - between);
	else if (chatBlock->typeMessage() == ChatBlock::Companion)
		chatBlock->setPos(0,
						  sceneRect().height() - chatBlock->height() - between);

	addItem(chatBlock);

	// Изменение вида блока
	int index = 0;
	while (index < mListBlocks.size() && chatBlock->typeMessage() == mListBlocks[index]->typeMessage()) {
		mListBlocks[index++]->isNotLastMessage();
	}

	// Добавление блока в начало списка
	mListBlocks.prepend(chatBlock);

	// Изменяем размер фона
	mRectBackground->setRect(sceneRect());
}

void ChatRegion_Scene::setFont(const QFont &font)
{
	mFont = font;
	foreach (ChatBlock *block, mListBlocks)
		block->resize(mSizeWindow.width());
	restartBlocks();
}

void ChatRegion_Scene::setBackgroundColor(const QColor &color)
{
	mRectBackground->setBrush(QBrush(color));
}

void ChatRegion_Scene::setUserColor(const QColor &text, const QColor &background)
{
	mUserTextColor = text;
	mUserBackgroundColor = background;
	foreach (ChatBlock *block, mListBlocks)
		block->update();
}

void ChatRegion_Scene::setCompanionColor(const QColor &text, const QColor &background)
{
	mCompanionTextColor = text;
	mCompanionBackgroundColor = background;
	foreach (ChatBlock *block, mListBlocks)
		block->update();
}

int ChatRegion_Scene::countBlocks() const
{
	return mListBlocks.size();
}

const ChatBlock *ChatRegion_Scene::getBlock(int i) const
{
	return mListBlocks.at(i);
}

void ChatRegion_Scene::deleteBlocks()
{
	foreach (ChatBlock *block, mListBlocks)
		delete block;
	mListBlocks.clear();
}

void ChatRegion_Scene::parentResized(const QSize &newSize)
{
	if (mStartHeight == 0) {
		if (sceneRect().height() < newSize.height())
			mStartHeight = newSize.height();
	} else {
		mStartHeight = newSize.height();
	}
	// Меняем ширину
	setSceneRect(QRectF(0, 0, newSize.width(), sceneRect().height()));

	mSizeWindow = newSize;

	// Меняем размеры блоков
	foreach (ChatBlock *block, mListBlocks)
		block->resize(mSizeWindow.width());
	// Меняем положение блоков
	restartBlocks();

	mRectBackground->setRect(sceneRect());
}

void ChatRegion_Scene::restartBlocks()
{
	int between = 5; /*разница между блоками*/


	qreal heightForScene = 0;
	foreach (ChatBlock *block, mListBlocks) {
		heightForScene += block->height() + between;
	}

	// Если высота для чата больше начальной
	if (mStartHeight == 0 || heightForScene > mStartHeight) {
		// Изменяем высоту (блоки смещать больше не придется)
		setSceneRect(0, 0, sceneRect().width(), heightForScene);
		// Смещение блоков
		qreal yPos = heightForScene - between;
		foreach (ChatBlock *block, mListBlocks) {
			if (block->typeMessage() == ChatBlock::User)
				block->setX(mSizeWindow.width() - block->width());
			else
				block->setX(0);
			block->setY(yPos - block->height());
			yPos -= block->height() + between;
		}
		mStartHeight = 0;
	}
	// Иначе если высота для чата меньше изначальной
	else {
		setSceneRect(0, 0, sceneRect().width(), mStartHeight);
		// Смещение блоков
		qreal yPos = mStartHeight - between;
		foreach (ChatBlock *block, mListBlocks) {
			if (block->typeMessage() == ChatBlock::User)
				block->setX(mSizeWindow.width() - block->width());
			else
				block->setX(0);
			block->setY(yPos - block->height());
			yPos -= block->height() + between;
		}
	}
}
