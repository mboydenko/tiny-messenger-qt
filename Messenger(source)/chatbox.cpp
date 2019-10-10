#include "chatbox.h"
#include "ui_chatbox.h"

#include "user.h"


ChatBox::ChatBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatBox)
{
    ui->setupUi(this);

    mChat = new ChatRegion(this);
	mChat->setFrameStyle(QFrame::NoFrame);

    mChat->setFont(QFont("Times New Roman", 14, QFont::Normal));
	mChat->setBackgroundColor(QColor(44, 56, 68));
	mChat->setUserColor(QColor(250, 250, 250), QColor(43, 82, 120));
	mChat->setCompanionColor(QColor(250, 250, 250), QColor(24, 37, 51));

	ui->textInput->installEventFilter(this);
    ui->chatLayout->addWidget(mChat);
    mDialog = nullptr;

	setTitle("Выберите диалог");
    hideChat();
}

ChatBox::~ChatBox()
{
    delete ui;
}

void ChatBox::setDialog(Dialog *dialog)
{
    mDialog = dialog;

    mChat->clearChat();


    ui->textInput->clear();

    Q_ASSERT(QObject::connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(sendMessage())));

    ui->title->setText(mDialog->companion());
    if(dialog->messages()->size() > 0)
    {
        for(auto it = mDialog->messages()->begin(); it != mDialog->messages()->end(); it++)
        {
            addMessage(*it);
        }
    }

	if (!mChatIsShow)
		showChat();
}

void ChatBox::addMessage(const QString &mes, const bool &ofCompanion)
{
    if(mDialog)
    {
        mChat->appendBlock(mes,ofCompanion);
    }
}

void ChatBox::addMessage(const Message *mes)
{
    if(mDialog)
    {
        addMessage(mes->message(),!mes->isMessageOfCompanion());
    }
}

QString ChatBox::getTitle() const
{
    if(mDialog)
        return mDialog->companion();
    else return nullptr;
}

void ChatBox::removeDialog()
{
    mDialog = nullptr;
    ui->title->setText("Выберите диалог");
    hideChat();
}

void ChatBox::setTitle(const QString &title)
{
    ui->title->setText(title);
}

void ChatBox::hideChat()
{
	mChatIsShow = false;

    mChat->hide();
    ui->textInput->hide();
    ui->sendButton->hide();

	static_cast<QVBoxLayout*>(layout())->insertStretch(1);
}

void ChatBox::showChat()
{
	mChatIsShow = true;

    mChat->show();
    ui->textInput->show();
    ui->sendButton->show();

	static_cast<QVBoxLayout*>(layout())->removeItem(layout()->itemAt(1));
}

void ChatBox::sendMessage()
{
    if(mDialog != nullptr){
        QString mes = ui->textInput->toPlainText(); // Сохраняем текст
        mes = mes.trimmed();
        if(mes != "")
        {
            ui->textInput->setText(""); // Отчищаем текст
            QString title = ui->title->text();
            mChat->appendBlock(mes,true);
            emit sendMessage(mes,title);
        }
    }
}

bool ChatBox::eventFilter(QObject *watched, QEvent *event)
{
	QWidget *wgt = static_cast<QWidget*>(watched);

	if (wgt == ui->textInput)
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
			if (keyEvent->modifiers() == Qt::KeyboardModifier::AltModifier &&
					keyEvent->key() == 16777220) {
				QTextEdit *editText = qobject_cast<QTextEdit*>(wgt);
				editText->append("");
				return true;
			} else if (keyEvent->key() == 16777220) {
				sendMessage();
				return true;
			}
		}

	return QWidget::eventFilter(watched, event);
}
