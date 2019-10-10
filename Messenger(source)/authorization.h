#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>

namespace Ui {
class Authorization;
}

class Authorization : public QWidget
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();


private:
    void setDefaultStyleSheet();
    void setErrorStyleSheet();

signals:
    void openRegistration();
    void sendData(const QString&, const QString&);

public slots:
    void invalidData();
    void serverNotAvailable();

private slots:

    void on_registrationButton_clicked();

    void on_loginButton_clicked();

    void on_passwordEdit_textEdited(const QString &);

    void on_loginEdit_textEdited(const QString &);

private:
    Ui::Authorization *ui;

	// QObject interface
public:
	bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;
};

#endif // AUTHORIZATION_H
