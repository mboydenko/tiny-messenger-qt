#ifndef ADDNEWDIALOGWINDOW_H
#define ADDNEWDIALOGWINDOW_H

#include <QDialog>

namespace Ui {
class AddNewDialogWindow;
}

class AddNewDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewDialogWindow(QWidget *parent = nullptr);
    ~AddNewDialogWindow();

private:
    void setErrorStyleSheet();

signals:
    void signalAddDialog(const QString&);

public slots:
    void userNotFound();
    void dialogAlreadyExists();
    void serverNotAvailable();

private slots:
    void on_addButton_clicked();
    void dialogAdded(const QString&);
    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::AddNewDialogWindow *ui;
};

#endif // ADDNEWDIALOGWINDOW_H
