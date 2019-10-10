#include "chatlistblock.h"
#include <QFontMetrics>
#include <QPainter>

#include <QDebug>

ChatListBlock::ChatListBlock(const QString &title,
							 const QString &text,
							 const QFont &titleFont,
							 const QFont &textFont,
							 const QColor &titleColor,
							 const QColor &textColor,
							 const QColor &backgroundColor,
							 const QColor &backgroundHoverColor,
							 const QColor &backgroundPressColor,
							 const QColor &newMessageColor,
							 const QColor &newMessageBackgroundColor,
							 QWidget *parent) :
	QWidget(parent),
	mTitleFont(titleFont),
	mTextFont(textFont),
	mTitleColor(titleColor),
	mTextColor(textColor),
	mBackgroundColor(backgroundColor),
	mBackgroundHoverColor(backgroundHoverColor),
	mBackgroundReleseColor(backgroundPressColor),
	mNMColor(newMessageColor),
	mNMBackgroundColor(newMessageBackgroundColor)
{
	mCountNewMessages = 0;

	mTitle	= title;
	mText	= text;

	mIsRelese	= false;
	mIsHovered	= false;
	mIsHide		= false;

	setFixedHeight(height());
}

int ChatListBlock::height() const
{
	QFontMetrics fmTitle(mTitleFont);
	QFontMetrics fmText(mTextFont);
	int between = 5;

	int height = between * 3 + fmTitle.height() + fmText.height();
	return height;
}

void ChatListBlock::takeOffClicked()
{
	mIsRelese = false;

	update();
}

void ChatListBlock::setTitle(const QString &title)
{
	mTitle = title;
	update();
}

void ChatListBlock::setText(const QString &text)
{
	mText = text;
	update();
}

QString ChatListBlock::title() const
{
	return mTitle;
}

QString ChatListBlock::text() const
{
	return mText;
}

void ChatListBlock::setHide()
{
	mIsHide = true;
}

void ChatListBlock::setShow()
{
	mIsHide = false;
}

bool ChatListBlock::isHided() const
{
	return mIsHide;
}

void ChatListBlock::setNeededUp()
{
	mIsNeededUp = true;
}

void ChatListBlock::clearNeededUp()
{
	mIsNeededUp = false;
}

bool ChatListBlock::isNeededUp() const
{
	return mIsNeededUp;
}

void ChatListBlock::paintEvent(QPaintEvent*)
{
	QFontMetrics fmTitle(mTitleFont);
	QFontMetrics fmText(mTextFont);
	int between = 5;

	// Draw Fon
	QPainter p(this);
	p.setPen(Qt::NoPen);
	if (mIsRelese)
		p.setBrush(mBackgroundReleseColor);
	else if (mIsHovered)
		p.setBrush(mBackgroundHoverColor);
	else
		p.setBrush(mBackgroundColor);
	p.drawRect(QRectF(0, 0, width(), height()));

	// Draw Title
	p.setPen(mTitleColor);
	p.setFont(mTitleFont);
	QRectF rect(between, between, width() - between, height() - between);
	QString title = fmTitle.elidedText(mTitle, Qt::ElideMiddle, int(rect.width()));
	p.drawText(rect, Qt::AlignLeft, title);

	// Draw Text
	p.setPen(mTextColor);
	p.setFont(mTextFont);
	rect.setY(between * 2 + fmTitle.height());
	QString text = fmTitle.elidedText(mText, Qt::ElideRight, int(rect.width()));
	p.drawText(rect, Qt::AlignLeft, text);

	// Draw Count new messages
	if (mCountNewMessages > 0)
	{
		p.setPen(Qt::NoPen);
		p.setBrush(mNMBackgroundColor);
		int widthEllipse = fmText.height() + between;
		rect.setX(width() - between - widthEllipse);
		rect.setY(rect.y() - between / 2);
		rect.setWidth(widthEllipse);
		rect.setHeight(widthEllipse);
		p.drawEllipse(rect);

		QFont fontCount = mTextFont;
		fontCount.setPointSize(fontCount.pointSize() - 1);
		fontCount.setBold(true);

		QFontMetrics fmCount(fontCount);

		QString count = mCountNewMessages > 9 ? QString("9+") : QString::number(mCountNewMessages);
		int widthCount = fmCount.horizontalAdvance(count);
		int heightCount = fmCount.height();

		rect.setX(rect.x() + (rect.width() - widthCount) / 2);
		rect.setY(rect.y() + (rect.height() - heightCount) / 2);
		rect.setWidth(widthCount);
		rect.setHeight(heightCount);
		p.setFont(fontCount);
		p.setPen(mNMColor);
		p.drawText(rect, Qt::AlignLeft, count);
	}
}


void ChatListBlock::mouseReleaseEvent(QMouseEvent *event)
{
	mIsRelese = true;

	// Перерисовка
	update();

	emit clicked();

	QWidget::mouseReleaseEvent(event);
}

void ChatListBlock::enterEvent(QEvent *event)
{
	mIsHovered = true;

	// Перерисовка
	update();

	QWidget::enterEvent(event);
}

void ChatListBlock::leaveEvent(QEvent *event)
{
	mIsHovered = false;

	// Перерисовка
	update();

	QWidget::leaveEvent(event);
}

void ChatListBlock::upCountNewMessages()
{
	mCountNewMessages++;
}

void ChatListBlock::clearCountNewMessages()
{
	mCountNewMessages = 0;
}
