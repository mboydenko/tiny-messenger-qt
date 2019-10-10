#include "registration.h"
#include "ui_registration.h"
#include "Other/buttonimage.h"

#include <QKeyEvent>
#include <QColor>

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);

	ui->settingsButton->setPicture(":/Images/settings.svg");
	ui->settingsButton->setPictureHover(":/Images/settings.svg");
	ui->settingsButton->setPicturePress(":/Images/settings_hover.svg");


    Q_ASSERT(connect(this,SIGNAL(openAuthorization()),parent,SLOT(openAuthorization())));

    ui->registrationButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->registerButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->authorizationButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    setObjectName("Registration");
    ui->registrationButton->setEnabled(false);
	ui->loginEdit->installEventFilter(this);
	ui->passwordEdit->installEventFilter(this);
	ui->passwordAgainEdit->installEventFilter(this);

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(44, 56, 68));
    setAutoFillBackground(true);
	setPalette(p);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::setDefaultStyleSheet()
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

    ui->passwordAgainEdit->setStyleSheet("QLineEdit"
                                         "{"
                                             "background-color: rgb(44, 56, 68);"
                                             "border-style: solid;"
                                             "border-color: rgb(74, 87, 94);"
                                             "border-width: 2;"
                                             "border-radius: 5px;"
                                             "color: rgb(126,132,138)"
                                         "}");
}

void Registration::setErrorStyleSheet()
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

    ui->passwordAgainEdit->setStyleSheet("QLineEdit"
                                         "{"
                                             "background-color: rgb(44, 56, 68);"
                                             "border-style: solid;"
                                             "border-color: red;"
                                             "border-width: 2;"
                                             "border-radius: 5px;"
                                             "color: rgb(126,132,138)"
                                         "}");
    ui->messageLable->setStyleSheet("color:red");
}

void Registration::setSuccessStyleSheet()
{
    ui->messageLable->setStyleSheet("color:green;");
}

bool Registration::isValidData()
{
    QString login = ui->loginEdit->text();
    for(auto it = login.begin(); it != login.end(); it++)
    {
        if(*it ==  " ")
        {
            setErrorStyleSheet();
            ui->messageLable->setText("Имя не должно содержать пробелов");
            return false;
        }
    }

    if(ui->loginEdit->text() == "" || ui->passwordEdit->text() == "" || ui->passwordAgainEdit->text() == "")
    {
        setErrorStyleSheet();
        ui->messageLable->setText("Все поля должны быть заполнены");
        return false;
    }

    if(ui->passwordEdit->text().length() < 8){
        setErrorStyleSheet();
        ui->messageLable->setText("Пароль должен состоять не менее чем из 8 символов");
        return false;
    }


    if(ui->passwordEdit->text() != ui->passwordAgainEdit->text())
    {
        setErrorStyleSheet();
        ui->messageLable->setText("Пароли не совпадают");
        return false;
    }

    return true;
}

void Registration::slotInvalibleUser()
{
    setErrorStyleSheet();
    ui->messageLable->setText("Имя пользователя не доступно");
}

void Registration::slotSuccessfulRegistration()
{
    setSuccessStyleSheet();
    ui->messageLable->setText("Аккаунт успешно создан");
}

void Registration::on_registerButton_clicked()
{
    if(isValidData())
    {
        emit sendData(ui->loginEdit->text(),ui->passwordEdit->text());
    }
}

void Registration::on_loginEdit_textEdited(const QString &)
{
    setDefaultStyleSheet();
    ui->messageLable->setText("");
}

void Registration::on_passwordEdit_textEdited(const QString &)
{
    setDefaultStyleSheet();
    ui->messageLable->setText("");
}

void Registration::on_passwordAgainEdit_textEdited(const QString &)
{
    setDefaultStyleSheet();
    ui->messageLable->setText("");
}

void Registration::serverNotAvailable()
{
    setErrorStyleSheet();
    ui->messageLable->setText("Сервер не доступен");
}

void Registration::on_authorizationButton_clicked()
{
    emit openAuthorization();
}

bool Registration::eventFilter(QObject *watched, QEvent *event)
{
	QWidget *wgt = qobject_cast<QWidget*>(watched);

	if (wgt == ui->loginEdit || wgt == ui->passwordEdit || wgt == ui->passwordAgainEdit)
		if (event->type() == QEvent::KeyPress)
		{
			QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
			if (keyEvent->key() == 16777220)
			{
				on_registerButton_clicked();
				return true;
			}
		}

	return QWidget::eventFilter(watched, event);
}
