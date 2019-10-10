#include "user.h"

User::User(QObject *parent) : QObject(parent)
{
    setObjectName("User");

    mListDialogs = new QList<Dialog*>;
    mHashDialogs = new QHash<QString,Dialog*>;
}

User::User(QString name, QString password, QObject *parent) : QObject (parent), mName(name), mPassword(password)
{
    setObjectName("User");

    mListDialogs = new QList<Dialog*>;
    mHashDialogs = new QHash<QString,Dialog*>;
}

User::~User()
{
    delete mListDialogs;
    delete mHashDialogs;
}

QString User::Name()
{
    return mName;
}

QString User::Password()
{
    return mPassword;
}

Dialog *User::getDialog(QString companion) const
{
    return mHashDialogs->value(companion);
}

QList<Dialog*> *User::dialogsList() const
{
    return mListDialogs;
}

void User::addDialog(QString companion)
{
   mHashDialogs->insert(companion,new Dialog(companion,this));
   mListDialogs->insert(0,mHashDialogs->value(companion));

   emit dialogAdded(companion);
   emit dialogsListChanged();
}

void User::removeDialog(QString companion)
{
    Dialog *dialog = getDialog(companion);
    mHashDialogs->remove(companion);

    for(auto it = mListDialogs->begin(); it != mListDialogs->end(); it++)
        if(*it == dialog)
        {
            mListDialogs->removeOne(dialog);
            delete dialog;
	    return;
        }
}


void User::moveToBeginning(Dialog *dialog)
{
    int position = mListDialogs->indexOf(dialog);
    mListDialogs->move(position,0);

    emit dialogsListChanged();
}

