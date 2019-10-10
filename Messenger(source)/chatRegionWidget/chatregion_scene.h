#ifndef CHATREGION_SCENE_H
#define CHATREGION_SCENE_H

#include <QGraphicsScene>

class ChatBlock;
class QGraphicsRectItem; /* фон */

class ChatRegion_Scene : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit ChatRegion_Scene(const QSize &sizeParent,
							  QObject *parent = Q_NULLPTR);
	~ChatRegion_Scene() Q_DECL_OVERRIDE;

	void appendBlock(const QString &message,
					 const bool &isUser);

	void setFont(const QFont &font);
	void setBackgroundColor(const QColor &color);
	void setUserColor(const QColor &text, const QColor &background);
	void setCompanionColor(const QColor &text, const QColor &background);

	int countBlocks() const;
	const ChatBlock * getBlock(int i) const;

	void deleteBlocks();

private slots:
	void parentResized(const QSize&);

private:
	QSize mSizeWindow;
	int mStartHeight;

	QList<ChatBlock*> mListBlocks;

	QGraphicsRectItem *mRectBackground;

	QFont	mFont;
	QColor	mUserTextColor;
	QColor	mUserBackgroundColor;
	QColor	mCompanionTextColor;
	QColor	mCompanionBackgroundColor;

	void restartBlocks();
};

#endif // CHATREGION_SCENE_H
