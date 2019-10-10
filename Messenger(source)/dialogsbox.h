#ifndef DIALOGSBOX_H
#define DIALOGSBOX_H

#include <QWidget>
#include <QList>
#include <QListWidgetItem>

#include "dialog.h"
#include "ChatList/chatlist.h"


namespace Ui {
class DialogsBox;
}

class DialogsBox : public QWidget
{
    Q_OBJECT

public:
    explicit DialogsBox(QWidget *parent = nullptr);
    ~DialogsBox();

public:
    //Загружает все диалоги у пользователя в список
    void loadDialogs(QList<Dialog*> *);
    //ДобавитьДиалог
    void addDialog(const QString&, const QString&);
    //Удалить дилалог из списка
    void deleteDialog(const QString&);
    //Установить последнее сообщение на диалог
    void setMessageToDialog(const QString& dialog, const QString& message);

    //Выбраный диалог
    QString currentDialogTitle() const;
    //Есть ли диалог
    bool isFound(const QString&);

signals:
    void signalDialogSelected(const QString&);
    void signalDeleteDialog(const QString&);

private slots:
    void searchDialog(QString str);
    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::DialogsBox *ui;

private:
	 ChatList *mDialogs;
};

#endif // DIALOGUESBOX_H
