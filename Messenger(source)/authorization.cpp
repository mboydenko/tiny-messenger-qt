#include "authorization.h"
#include "ui_authorization.h"
#include <QKeyEvent>

Authorization::Authorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);

	ui->settingsButton->setPicture(":/Images/settings.svg");
	ui->settingsButton->setPictureHover(":/Images/settings.svg");
	ui->settingsButton->setPicturePress(":/Images/settings_hover.svg");

    ui->loginButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->authorizationButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->registrationButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    Q_ASSERT(connect(this,SIGNAL(openRegistration()),parent,SLOT(openRegistration())));

    setObjectName("Authorization");


    ui->authorizationButton->setFlat(false);
	ui->loginEdit->installEventFilter(this);
	ui->passwordEdit->installEventFilter(this);

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(44, 56, 68));
    setAutoFillBackground(true);
	setPalette(p);
}

Authorization::~Authorization()
{
    delete ui;
}


void Authorization::setDefaultStyleSheet()
{
    ui->loginEdit->setStyleSheet("QLineEdit"
                                 "{"
                                     "background-color: rgb(44, 56, 68);"
                                     "border-style: solid;"
                                     "border-color: rgb(74, 87, 94);"
                                     "border-width: 2;"
                                     "border-radius: 5px;"
                                     "color: rgb(126,132,138)"
                                 "}");
    ui->passwordEdit->setStyleSheet("QLineEdit"
                                    "{"
                                        "background-color: rgb(44, 56, 68);"
                                        "border-style: solid;"
                                        "border-color: rgb(74, 87, 94);"
                                        "border-width: 2;"
                                        "border-radius: 5px;"
                                        "color: rgb(126,132,138)"
                                    "}");
    ui->messageLable->setStyleSheet("color:red");
}

void Authorization::setErrorStyleSheet()
{
    ui->loginEdit->setStyleSheet("QLineEdit"
                                 "{"
                                     "background-color: rgb(44, 56, 68);"
                                     "border-style: solid;"
                                     "border-color: red;"
                                     "border-width: 2;"
                                     "border-radius: 5px;"
                                     "color: rgb(126,132,138)"
                                 "}");
    ui->passwordEdit->setStyleSheet("QLineEdit"
                                    "{"
                                        "background-color: rgb(44, 56, 68);"
                                        "border-style: solid;"
                                        "border-color: red;"
                                        "border-width: 2;"
                                        "border-radius: 5px;"
                                        "color: rgb(126,132,138)"
                                    "}");
    ui->messageLable->setStyleSheet("color:red;");
}

void Authorization::on_registrationButton_clicked()
{
    emit openRegistration();
}

void Authorization::on_loginButton_clicked()
{
    emit sendData(ui->loginEdit->text(),ui->passwordEdit->text());
}

void Authorization::on_passwordEdit_textEdited(const QString&)
{
    setDefaultStyleSheet();
    ui->messageLable->setText("");
}

void Authorization::on_loginEdit_textEdited(const QString&)
{
    setDefaultStyleSheet();
    ui->messageLable->setText("");
}

void Authorization::invalidData()
{
    setErrorStyleSheet();
    ui->messageLable->setText("Неверное имя пользователя или пароль");
}

void Authorization::serverNotAvailable()
{
    setErrorStyleSheet();
    ui->messageLable->setText("Сервер не доступен");
}

bool Authorization::eventFilter(QObject *watched, QEvent *event)
{
	QWidget *wgt = qobject_cast<QWidget*>(watched);

	if (wgt == ui->loginEdit || wgt == ui->passwordEdit)
		if (event->type() == QEvent::KeyPress)
		{
			QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
			if (keyEvent->key() == 16777220)
			{
				on_loginButton_clicked();
				return true;
			}
		}

	return QWidget::eventFilter(watched, event);
}
