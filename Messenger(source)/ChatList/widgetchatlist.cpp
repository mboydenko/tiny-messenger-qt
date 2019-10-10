#include "widgetchatlist.h"
#include "chatlistblock.h"
#include <QVBoxLayout>
#include <algorithm> // std::find

WidgetChatList::WidgetChatList(QWidget *parent) :
	QFrame(parent),
	mBlockLastClicked(Q_NULLPTR)
{
	resize(parent->width(), 0);

	QVBoxLayout *layout = new QVBoxLayout(this);
	setLayout(layout);

	mTitleFont	= QFont("Arial", 16, QFont::Bold);
	mTextFont	= QFont("Arial", 14, QFont::Normal);

	mTitleColor = QColor(0, 0, 0);
	mTextColor	= QColor(0, 0, 0);

	mBackgroundColor = QColor(250, 250, 250);
	mBackgroundHoverColor = QColor(200, 200, 200);
	mBackgroundReleaseColor = QColor(160, 160, 160);
}

WidgetChatList::~WidgetChatList()
{

}

void WidgetChatList::appendBlock(const QString &title, const QString &text)
{
	ChatListBlock *block = new ChatListBlock(title,
											 text,
											 mTitleFont,
											 mTextFont,
											 mTitleColor,
											 mTextColor,
											 mBackgroundColor,
											 mBackgroundHoverColor,
											 mBackgroundReleaseColor,
											 mNewMessageColor,
											 mNewMessageBackgroundColor,
											 this);
	connect(block, SIGNAL(clicked()),
			this, SLOT(blockWasClicked()));

	resize(width(), height() + block->height());
	block->resize(width(), block->height());
	block->move(0, mListBlocks.size() * block->height() /*высота у всех блоков одинаковая*/);
	block->show();

    mListBlocks.append(block);
}

void WidgetChatList::upBlock(const int &index)
{
    if (index != -1)
    {
        // Если блок спрятан, устанавливаем аттрибут на необходимость поднять его после показа
        if (mListBlocks[index]->isHided())
        {
            mListBlocks[index]->setNeededUp();
        }
        else
        {
            for (int i = index; i != 0; i--)
            {
                mListBlocks.swap(i, i - 1);
                ChatListBlock *swap_block = mListBlocks[i];
                swap_block->move(0, swap_block->y() + swap_block->height());
            }
            // Перемещаем основной блок
            mListBlocks[0]->move(0, 0);
        }
    }
}

void WidgetChatList::upBlock(const QString &title)
{
	int index = mListBlocks.indexOf(*(std::find(mListBlocks.begin(), mListBlocks.end(), title)));
    upBlock(index);
}

void WidgetChatList::changeTitle(const QString &title, const QString &newTitle)
{
	int index = mListBlocks.indexOf(*(std::find(mListBlocks.begin(), mListBlocks.end(), title)));

	if (index != -1)
	{
		mListBlocks[index]->setTitle(newTitle);
	}
}

void WidgetChatList::changeText(const int &index, const QString &newText)
{
    if (index != -1)
	{
		mListBlocks[index]->setText(newText);

		if (mListBlocks[index] != mBlockLastClicked)
		{
			mListBlocks[index]->upCountNewMessages();
		}
	}
}

void WidgetChatList::changeText(const QString &title, const QString &newText)
{
	int index = mListBlocks.indexOf(*(std::find(mListBlocks.begin(), mListBlocks.end(), title)));
    changeText(index,newText);
}

void WidgetChatList::deleteBlock(const int &index)
{
    if (index != -1)
    {
        if (mListBlocks[index]->isHided()) // Если блок спрятан, то не можем удалить
            return;

        if (mListBlocks[index] == mBlockLastClicked)
              mBlockLastClicked = Q_NULLPTR;

        resize(width(), height() - mListBlocks[index]->height());
        // Перемещаем сначала все блоки что ниже удаляемого выше
        for (int i = index + 1; i < mListBlocks.size(); i++)
        {
            ChatListBlock *block = mListBlocks[i];
            block->move(0, block->y() - block->height());
        }
        // Теперь удаляем
        ChatListBlock *deleted_block = mListBlocks[index];
        mListBlocks.removeAt(index);
        delete deleted_block;

       // emit deleted(title);
    }
}

void WidgetChatList::deleteBlock(const QString &title)
{
	int index = mListBlocks.indexOf(*(std::find(mListBlocks.begin(), mListBlocks.end(), title)));
    deleteBlock(index);
}

void WidgetChatList::hideBlock(const int &index)
{
    if (index != -1)
    {
        // Если блок не спрятан, то прячем
        if (!mListBlocks[index]->isHided())
        {
            resize(width(), height() - mListBlocks[index]->height());
            // Перемещаем сначала все блоки что ниже спрятанного выше
            for (int i = index + 1; i < mListBlocks.size(); i++)
            {
                ChatListBlock *block = mListBlocks[i];
                block->move(0, block->y() - block->height());
            }

            ChatListBlock *hided_block = mListBlocks[index];
            hided_block->hide();
            hided_block->setHide();
        }
    }
}

void WidgetChatList::hideBlock(const QString &title)
{
	int index = mListBlocks.indexOf(*(std::find(mListBlocks.begin(), mListBlocks.end(), title)));
    hideBlock(index);
}

void WidgetChatList::showBlock(const int &index)
{
    if (index != -1)
    {
        // Если блок спрятан, то показываем его
        if (mListBlocks[index]->isHided())
        {
            resize(width(), height() + mListBlocks[index]->height());
            // Перемещаем сначала все блоки что ниже спрятанного выше
            for (int i = index + 1; i < mListBlocks.size(); i++)
            {
                ChatListBlock *block = mListBlocks[i];
                block->move(0, block->y() + block->height());
            }

            ChatListBlock *hided_block = mListBlocks[index];
            hided_block->show();
            hided_block->setShow();

            // Если блок необходимо было поднять пока он был спрятан - поднимаем сейчас
            if (hided_block->isNeededUp())
            {
                upBlock(index);
                hided_block->clearNeededUp();
            }
        }
    }
}

void WidgetChatList::showBlock(const QString &title)
{
	int index = mListBlocks.indexOf(*(std::find(mListBlocks.begin(), mListBlocks.end(), title)));
    showBlock(index);
}

void WidgetChatList::showBlocks()
{
	foreach (ChatListBlock *block, mListBlocks)
	{
		if (block->isHided())
		{
			showBlock(block->title());
		}
	}
}

void WidgetChatList::setBackgroundColor(const QColor &color)
{
	mBackgroundColor = color;
}

void WidgetChatList::setBackgroundHoverColor(const QColor &color)
{
	mBackgroundHoverColor = color;
}

void WidgetChatList::setBackgroundReleaseColor(const QColor &color)
{
	mBackgroundReleaseColor = color;
}

void WidgetChatList::setTitleFont(const QFont &font)
{
	mTitleFont = font;
}

void WidgetChatList::setTitleColor(const QColor &color)
{
	mTitleColor = color;
}

void WidgetChatList::setTextFont(const QFont &font)
{
	mTextFont = font;
}

void WidgetChatList::setTextColor(const QColor &color)
{
	mTextColor = color;
}

int WidgetChatList::countBlocks() const
{
    return mListBlocks.size();
}

bool WidgetChatList::blockIsHided(const QString &title) const
{
    int index = mListBlocks.indexOf(*(std::find(mListBlocks.begin(), mListBlocks.end(), title)));
    return blockIsHided(index);
}

bool WidgetChatList::blockIsHided(const int &index) const
{
    ChatListBlock *block = mListBlocks[index];
    if(block->isHided())
        return true;
    else return false;
}

QString WidgetChatList::currentDialogTitle() const
{
	if (mBlockLastClicked != Q_NULLPTR)
		return mBlockLastClicked->title();
	return QString(""); // Если не выбран никакой диалог - вернем пустую строку
}

QString WidgetChatList::currentDialogText() const
{
	if (mBlockLastClicked != Q_NULLPTR)
		return mBlockLastClicked->text();
	return QString(""); // Если не выбран никакой диалог - вернем пустую строку
}

QString WidgetChatList::dialogTitle(const int &index) const
{
	return mListBlocks[index]->title();
}

QString WidgetChatList::dialogText(const int &index) const
{
    return mListBlocks[index]->text();
}

bool WidgetChatList::isFound(const QString &title)
{
    for(int i = 0; i < mListBlocks.count(); i++)
    {
        if(title == dialogTitle(i))
            return true;
    }
    return false;
}

void WidgetChatList::parentResized(const QSize &newSize)
{
	resize(newSize.width(), height());
	foreach (ChatListBlock *block, mListBlocks)
	{
		block->resize(newSize.width(), block->height());
    }
}

void WidgetChatList::blockWasClicked()
{
	ChatListBlock *block = static_cast<ChatListBlock*>(sender());

	if (block != mBlockLastClicked)
	{
		if (mBlockLastClicked != Q_NULLPTR)
		{
			mBlockLastClicked->takeOffClicked();
		}
		mBlockLastClicked = block;
		block->clearCountNewMessages();

		emit clicked(block->title());
	}
}

void WidgetChatList::setNewMessageColor(const QColor &color)
{
	mNewMessageColor = color;
}
void WidgetChatList::setNewMessageBackgroundColor(const QColor &color)
{
	mNewMessageBackgroundColor = color;
}
void WidgetChatList::upNewMessage(const QString &title)
{
	int index = mListBlocks.indexOf(*(std::find(mListBlocks.begin(), mListBlocks.end(), title)));

	if (index != -1)
	{
		mListBlocks[index]->upCountNewMessages();
	}
}
void WidgetChatList::clearNewMessages(const QString &title)
{
	int index = mListBlocks.indexOf(*(std::find(mListBlocks.begin(), mListBlocks.end(), title)));

	if (index != -1)
	{
		mListBlocks[index]->clearCountNewMessages();
	}
}
