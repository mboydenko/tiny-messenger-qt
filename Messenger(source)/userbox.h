#ifndef USERBOX_H
#define USERBOX_H

#include <QWidget>

namespace Ui {
class UserBox;
}

class UserBox : public QWidget
{
    Q_OBJECT

public:
    explicit UserBox(QWidget *parent = nullptr);
    ~UserBox();

public:
    void setUser(QString);

signals:
    void signalExit();
private:
    Ui::UserBox *ui;
};

#endif // USERBOX_H
