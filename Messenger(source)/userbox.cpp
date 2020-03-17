#include "userbox.h"
#include "ui_userbox.h"
#include <QVBoxLayout>
#include <QKeyEvent>

UserBox::UserBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserBox)
{
    ui->setupUi(this);

	ui->exitButton->setPicture(":/Images/exit.svg");
	ui->exitButton->setPictureHover(":/Images/exit.svg");
	ui->exitButton->setPicturePress(":/Images/exit_hover.svg");

    Q_ASSERT(connect(ui->exitButton, SIGNAL(clicked()),this,SIGNAL(signalExit())));

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(55, 71, 87));
    setAutoFillBackground(true);
    setPalette(p);
}

UserBox::~UserBox()
{
    delete ui;
}

void UserBox::setUser(QString name)
{
    ui->userName->setText(name);
}
