#ifndef CHATREGION_H
#define CHATREGION_H

#include <QGraphicsView>

class ChatRegion_Scene;

namespace Chat
{
	struct Block
	{
		QString message;
        bool isUser;
	};
}

class ChatRegion : public QGraphicsView
{
    Q_OBJECT

public:
	ChatRegion(QWidget *parent = Q_NULLPTR);
	~ChatRegion() Q_DECL_OVERRIDE;

	void setFont(const QFont &font);
	void setBackgroundColor(const QColor &color);
	void setUserColor(const QColor &text, const QColor &background);
	void setCompanionColor(const QColor &text, const QColor &background);

	QList<Chat::Block> getMessages() const;

	void loadChat(const QList<Chat::Block> &list);
	void clearChat();

private:
	ChatRegion_Scene *mScene;
	QString mCss;

signals:
	void resized(const QSize&);

public slots:
	void appendBlock(const QString &message,
                     const bool &isUser);

protected:
	void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
};
#endif // CHATREGION_H
