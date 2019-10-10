#include "dialog.h"

Dialog::Dialog(const QString &comp,
               QObject *parent)
    : QObject (parent)
{
    mCompanion = comp;
    mMessages = new QList<Message*>;
}

Dialog::~Dialog()
{
    delete mMessages;
}

void Dialog::addMessage(const QString &str, bool ofCompanion)
{
    mMessages->append(new Message(str, ofCompanion,this));

    QMetaObject::invokeMethod(parent(),"moveToBeginning",Q_ARG(Dialog*,this));

    emit dialogChanged();
}

QString Dialog::companion() const
{
    return mCompanion;
}

QList<Message *> *Dialog::messages() const
{
    return mMessages;
}
