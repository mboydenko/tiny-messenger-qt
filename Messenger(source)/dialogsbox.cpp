#include "dialogsbox.h"
#include "ui_dialogsbox.h"
#include "addnewdialogwindow.h"

#include <QDebug>
#include <QString>

DialogsBox::DialogsBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogsBox)
{
    ui->setupUi(this);

	setAutoFillBackground(true);
	QPalette pal = palette();
	pal.setColor(QPalette::Background, QColor(44, 56, 68));
	setPalette(pal);

	mDialogs = new ChatList(this);
	mDialogs->setBackgroundColor(QColor(55, 71, 87));
	mDialogs->setBackgroundHoverColor(QColor(38, 50, 63));
	mDialogs->setBackgroundReleaseColor(QColor(43, 82, 120));
	mDialogs->setTitleColor(QColor(250, 250, 250));
	mDialogs->setTextColor(QColor(200, 200, 200));
	mDialogs->setFrameStyle(QFrame::NoFrame);
    mDialogs->setNewMessageBackgroundColor(QColor(187,187,187));

    ui->layoutForDialogList->addWidget(mDialogs);

    Q_ASSERT(QObject::connect
             (
                 ui->searchLineEdit,    SIGNAL(textEdited(QString)),
                 this,                  SLOT(searchDialog(QString)))
             );
    Q_ASSERT(QObject::connect
             (
                mDialogs,               SIGNAL(clicked(const QString&)),
                this,                   SIGNAL(signalDialogSelected(const QString&)))
             );
}

DialogsBox::~DialogsBox()
{
    delete ui;
}

void DialogsBox::loadDialogs(QList<Dialog *> *dialogs)
{
    if(!dialogs->isEmpty())
    {
        for(auto it = dialogs->begin(); it != dialogs->end(); it++)
        {
            Dialog *d = *it;
            QString title = d->companion();
            QString message;

            if(!d->messages()->isEmpty())
            {
                message = d->messages()->last()->message();
                if(!d->messages()->last()->isMessageOfCompanion())
                    message = "Вы: " + message;
            }
			mDialogs->appendDialog(title,message);
        }
    }
}

void DialogsBox::addDialog(const QString &title, const QString &message)
{
	mDialogs->appendDialog(title, message);
	mDialogs->upDialog(title);
}

void DialogsBox::deleteDialog(const QString &title)
{
	mDialogs->deleteDialog(title);
}

QString DialogsBox::currentDialogTitle() const
{
	return mDialogs->currentDialog().title;
}

bool DialogsBox::isFound(const QString &dialog)
{
    return mDialogs->isFound(dialog);
}

void DialogsBox::setMessageToDialog(const QString &dialog, const QString &message)
{
    if(mDialogs->isFound(dialog))
    {
        mDialogs->changeText(dialog,message);
		mDialogs->upDialog(dialog);
    }
    else {
        addDialog(dialog,message);
        mDialogs->changeText(dialog,message);
		mDialogs->upDialog(dialog);
    }
}

void DialogsBox::searchDialog(QString str)
{
    str = str.trimmed();
    str = str.toLower();

	mDialogs->showDialogs();

	for(int i = 0; i < mDialogs->dialogs().size(); i++)
    {
		QString title = mDialogs->dialogs()[i].title;
        title = title.toLower();

        if(title.count() < str.count())
        {
			mDialogs->hideDialog(mDialogs->dialogs()[i].title);
        }
        for (int j = 0; j < str.count(); j++)
        {
            if(str[j] != title[j])
            {
				mDialogs->hideDialog(mDialogs->dialogs()[i].title);
                break;
            }
        }
    }
}


void DialogsBox::on_addButton_clicked()
{
    AddNewDialogWindow *dialogWindow = new AddNewDialogWindow(this);
    dialogWindow->setModal(true);

    QObject *client = parent()->parent()->parent()->findChild<QObject*>("client");

    if(client)
    {
        Q_ASSERT(QObject::connect(client,SIGNAL(signalUserNotFound()),dialogWindow,SLOT(userNotFound())));
        Q_ASSERT(QObject::connect(client,SIGNAL(signalServerNotAvailable()),dialogWindow,SLOT(serverNotAvailable())));
        Q_ASSERT(QObject::connect(client,SIGNAL(signalAddDialog(const QString&)),dialogWindow,SLOT(dialogAdded(const QString&))));
        Q_ASSERT(QObject::connect(dialogWindow,SIGNAL(signalAddDialog(const QString&)),client,SLOT(slotAddDialog(const QString&))));
    }

    dialogWindow->show();
}

void DialogsBox::on_deleteButton_clicked()
{
	QString title = mDialogs->currentDialog().title;
	mDialogs->deleteDialog(title);
    emit signalDeleteDialog(title);
    return;
}
