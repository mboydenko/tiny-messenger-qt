#ifndef CHATBLOCK_H
#define CHATBLOCK_H

#include <QGraphicsItem>
#include <QFont>

class ChatBlock : public QGraphicsItem
{
public:
	enum TypeMessage { User, Companion };

	ChatBlock(const int &widthWindow,
			  const QString &message,
			  const TypeMessage &typeMessage,
			  QFont &font,
			  QColor &userTextColor,
			  QColor &userBackgroundColor,
			  QColor &companionTextColor,
			  QColor &companionBackgroundColor,
			  QGraphicsItem *parent = Q_NULLPTR);

	QRectF	boundingRect() const Q_DECL_OVERRIDE;
	void	paint(QPainter *, const QStyleOptionGraphicsItem*, QWidget*) Q_DECL_OVERRIDE;

	qreal	width() const;
	qreal	height() const;

	const QString &message() const;
	TypeMessage typeMessage() const;

	void resize(const int &widthWindow);

	void isNotLastMessage();

private:
	QString		mMessage;
	QStringList mListMessage;
	QRectF		mRectObject;
	TypeMessage mTypeMessage;

	const QFont	 &mFont;
	const QColor &mUserTextColor;
	const QColor &mUserBackgroundColor;
	const QColor &mCompanionTextColor;
	const QColor &mCompanionBackgroundColor;

	qint32	mBorderRight;
	qint32	mBorderInBlock;

	bool	mIsLastMessage;
};

#endif // CHATBLOCK_H
