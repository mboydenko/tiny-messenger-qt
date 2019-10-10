#ifndef BUTTONIMAGE_H
#define BUTTONIMAGE_H

#include <QPushButton>

class ButtonImage : public QPushButton
{
	Q_OBJECT
public:
	using QPushButton::QPushButton;

	void setPicture(const QString &path);
	void setPictureHover(const QString &path);
	void setPicturePress(const QString &path);

protected:
	enum { None, Hover, Press } mType;

	QImage fromSvg(const QString &path, const QSize &size);

	QImage m_pixMap;
	QImage m_pixMapHover;
	QImage m_pixMapPress;
	void enterEvent(QEvent *event) Q_DECL_OVERRIDE;
	void leaveEvent(QEvent *event) Q_DECL_OVERRIDE;
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // BUTTONIMAGE_H
