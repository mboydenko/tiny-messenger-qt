#include "chatblock.h"
#include <QFontMetrics>
#include <QPainter>

ChatBlock::ChatBlock(const int &widthWindow,
					 const QString &message,
					 const TypeMessage &typeMessage,
					 QFont &font,
					 QColor &userTextColor,
					 QColor &userBackgroundColor,
					 QColor &companionTextColor,
					 QColor &companionBackgroundColor,
					 QGraphicsItem *parent)
	: QGraphicsItem(parent),
	  mFont(font),
	  mUserTextColor(userTextColor),
	  mUserBackgroundColor(userBackgroundColor),
	  mCompanionTextColor(companionTextColor),
	  mCompanionBackgroundColor(companionBackgroundColor)
{	
	mMessage		= message;
	mTypeMessage	= typeMessage;
	mIsLastMessage	= true;

	mBorderRight	= 8;
	mBorderInBlock	= 6;

	resize(widthWindow);
}

void ChatBlock::resize(const int &widthWindow)
{
	mListMessage.clear();

	QFontMetrics fm(mFont);
	// 1* Разбиение текста на строки по размеру
	{
		int width = widthWindow / 2 - mBorderInBlock * 2 - mBorderRight;

		QStringList str_split = mMessage.split(" ");

		// Отдельная строка
		QString commonStr;
		while (!str_split.isEmpty()) {
			QString &str = str_split.first();
			if (fm.horizontalAdvance(str) > width) {
				if (!commonStr.isEmpty()) {
					commonStr.remove(commonStr.size() - 1, 1);
					mListMessage.append(commonStr);
					commonStr.clear();
				}
				QString anotherStr;
				while (fm.horizontalAdvance(anotherStr) < width) {
					anotherStr += str.front();
					str.remove(0, 1);
				}
				str.insert(0, anotherStr.back());
				anotherStr.remove(anotherStr.size() - 1, 1);
				mListMessage.append(anotherStr);
			} else {
				if (fm.horizontalAdvance(commonStr + str) > width) {
					commonStr.remove(commonStr.size() - 1, 1);
					mListMessage.append(commonStr);
					commonStr.clear();
					commonStr += str + " ";
				} else {
					commonStr += str + " ";
				}
				str_split.removeFirst();
			}
		}
		if (!commonStr.isEmpty()) {
			commonStr.remove(commonStr.size() - 1, 1);
			mListMessage.append(commonStr);
		}
	}

	// 2* Вычисление размеров блока
	int minimalWidth = 0;
	int width = mBorderInBlock * 2 + mBorderRight;
	int height = mBorderInBlock * 2;
	foreach (const QString &str, mListMessage) {
		height += fm.lineSpacing();
		if (minimalWidth < fm.horizontalAdvance(str))
			minimalWidth = fm.horizontalAdvance(str);
	}
	width += minimalWidth;

	mRectObject = QRectF(QPointF(0, 0), QSize(width, height));

	// Перерисовка
	update();
}

QRectF ChatBlock::boundingRect() const
{
	return mRectObject;
}

void ChatBlock::paint(QPainter *ppainter, const QStyleOptionGraphicsItem *, QWidget *)
{
	int xPosText = 0;
	int yPosText = 0;

	ppainter->setRenderHint(QPainter::Antialiasing, true);
	ppainter->setPen(Qt::NoPen);
	ppainter->setFont(mFont);
	// 1* Отрисовка блока
	if (mTypeMessage == User) {
		ppainter->setBrush(QBrush(mUserBackgroundColor));
		if (!mIsLastMessage) {
			ppainter->drawRoundedRect(QRectF(0,
											 0,
											 boundingRect().width() - mBorderRight,
											 boundingRect().height()),
									  10,
									  10);
		} else {
			ppainter->drawRoundedRect(QRectF(0,
											 0,
											 boundingRect().width() - mBorderRight,
											 boundingRect().height()),
									  10,
									  10);
			QPolygonF polygon;
			polygon << QPointF(boundingRect().width() / 2 - 3,
							   boundingRect().height())
					<< QPointF(boundingRect().width(),
								boundingRect().height())
					<< QPointF(boundingRect().width() - 20,
							   boundingRect().height() - 20);
			ppainter->drawPolygon(polygon);
		}
		xPosText = mBorderInBlock;
	} else if (mTypeMessage == Companion) {
		ppainter->setBrush(QBrush(mCompanionBackgroundColor));
		if (!mIsLastMessage) {
			ppainter->drawRoundedRect(QRectF(mBorderRight,
											 0,
											 boundingRect().width()  - mBorderRight,
											 boundingRect().height()),
									  10,
									  10);
		} else {
			ppainter->drawRoundedRect(QRectF(mBorderRight,
											 0,
											 boundingRect().width() - mBorderRight,
											 boundingRect().height()),
									  10,
									  10);
			QPolygonF polygon;
			polygon << QPointF(boundingRect().width() / 2 + 3,
							   boundingRect().height())
					<< QPointF(0,
							   boundingRect().height())
					<< QPointF(20,
							   boundingRect().height() - 20);
			ppainter->drawPolygon(polygon);
		}

		xPosText = mBorderInBlock + mBorderRight;
	}

	// 2* Отрисовка текста в блоке
	mTypeMessage == User ? ppainter->setPen(mUserTextColor) :
						   ppainter->setPen(mCompanionTextColor);
	yPosText = QFontMetrics(mFont).lineSpacing();
	foreach (const QString &str, mListMessage) {
		ppainter->drawText(QPointF(xPosText, yPosText), str);
		yPosText += QFontMetrics(mFont).lineSpacing();
	}
}

const QString &ChatBlock::message() const
{
	return mMessage;
}

qreal ChatBlock::width() const
{
	return boundingRect().width();
}

qreal ChatBlock::height() const
{
	return boundingRect().height();
}

ChatBlock::TypeMessage ChatBlock::typeMessage() const
{
	return mTypeMessage;
}

void ChatBlock::isNotLastMessage()
{
	mIsLastMessage = false;
	update();
}
