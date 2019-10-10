#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();


signals:
    //Открыть окно авторизации
    void openAuthorization();
    //Отправить данные на сервер
    void sendData(const QString&, const QString&);
private:

    void setDefaultStyleSheet();
    void setErrorStyleSheet();
    void setSuccessStyleSheet();

    bool isValidData();

public slots:
    void slotInvalibleUser();
    void slotSuccessfulRegistration();
    void serverNotAvailable();

private slots:
    void on_registerButton_clicked();

    void on_loginEdit_textEdited(const QString &arg1);

    void on_passwordEdit_textEdited(const QString &arg1);

    void on_passwordAgainEdit_textEdited(const QString &arg1);

    void on_authorizationButton_clicked();

private:
    Ui::Registration *ui;


	// QObject interface
public:
	bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;
};

#endif // REGISTRATION_H
