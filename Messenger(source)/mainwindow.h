#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "user.h"
#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

signals:
    void dialogsListChanged();

public slots:
    //Устанавливаем пользователя
    void setUser(const User&);
    //Открывает окно регистрации
    void openRegistration();
    //Открывает окно авториазции
    void openAuthorization();
    //Отклывает менб пользователя
    void openUserWindow(const User&);
    //Сменить пользователя
    Q_INVOKABLE void changeUser();
private:
    QWidget *centerWidget{nullptr};
    Client *client;
};

#endif // MAINWINDOW_H
