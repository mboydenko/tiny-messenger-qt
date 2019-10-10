#ifndef CHATLISTBLOCK_H
#define CHATLISTBLOCK_H

#include <QWidget>

class ChatListBlock : public QWidget
{
	Q_OBJECT
public:
	explicit ChatListBlock(const QString &title,
						   const QString &text,
						   const QFont &titleFont,
						   const QFont &textFont,
						   const QColor &titleColor,
						   const QColor &textColor,
						   const QColor &backgroundColor,
						   const QColor &backgroundHoverColor,
						   const QColor &backgroundReleaseColor,
						   const QColor &newMessageColor,
						   const QColor &newMessageBackgroundColor,
						   QWidget *parent = nullptr);

	int height() const;

	void takeOffClicked();

	void setTitle(const QString &title);
	void setText(const QString &text);

	QString title() const;
	QString text() const;

	void setHide();			// Устанавливаем аттрибут "скрытый"
	void setShow();			// Устанавливаем аттрибут "не скрытый"
	bool isHided() const;

	void setNeededUp();		// Необходимо поднять после показа
	void clearNeededUp();	// Убрать необходимость поднятия
	bool isNeededUp() const;

	void upCountNewMessages();
	void clearCountNewMessages();

private:
	QString		 mTitle;
	QString		 mText;

	const QFont	 &mTitleFont;
	const QFont  &mTextFont;
	const QColor &mTitleColor;
	const QColor &mTextColor;

	const QColor &mBackgroundColor;
	const QColor &mBackgroundHoverColor;
	const QColor &mBackgroundReleseColor;

	bool mIsRelese;
	bool mIsHovered;
	bool mIsHide;
	bool mIsNeededUp; // if block is hide = true

	const QColor &mNMColor; // NM - New Message
	const QColor &mNMBackgroundColor;

	int mCountNewMessages;

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void enterEvent(QEvent *event) Q_DECL_OVERRIDE;
	void leaveEvent(QEvent *event) Q_DECL_OVERRIDE;

signals:
	void clicked();
};

inline bool operator==(ChatListBlock *block, const QString &title)
{
	return block->title() == title ? true : false;
}

#endif // CHATLISTBLOCK_H
