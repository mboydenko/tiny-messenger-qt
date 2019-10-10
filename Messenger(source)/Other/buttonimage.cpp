#include "buttonimage.h"
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QMouseEvent>

void ButtonImage::setPicture(const QString &path)
{
	mType = None;
	m_pixMap = fromSvg(path, size());
}

void ButtonImage::setPictureHover(const QString &path)
{
	mType = None;
	m_pixMapHover = fromSvg(path, size());
}

void ButtonImage::setPicturePress(const QString &path)
{
	mType = None;
	m_pixMapPress = fromSvg(path, size());
}

QImage ButtonImage::fromSvg(const QString &path, const QSize &size)
{
	QSvgRenderer renderer(path);

	QImage image(size.width(), size.height(), QImage::Format_ARGB32);
	image.fill(0x00ffffff);
	QPainter painter(&image);
	renderer.render(&painter);

	return image;
}

void ButtonImage::enterEvent(QEvent *)
{
	mType = Hover;
}

void ButtonImage::leaveEvent(QEvent *)
{
	mType = None;
}

void ButtonImage::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);
	QImage image = mType == None ? m_pixMap :
								   mType == Hover ? m_pixMapHover :
													m_pixMapPress;
	//image = image.scaled(width(), height());
	p.drawImage(rect(), image);
}


void ButtonImage::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
		mType = Press;

	QPushButton::mousePressEvent(event);
}


void ButtonImage::mouseReleaseEvent(QMouseEvent *event)
{
	mType = None;

	QPushButton::mouseReleaseEvent(event);
}
