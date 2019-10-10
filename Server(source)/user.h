#ifndef USER_H
#define USER_H

#include <QObject>
#include <QList>
#include <QHash>
#include <QDataStream>

#include "dialog.h"

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    explicit User(QString name, QString password, QObject *parent = nullptr);

    ~User();

public:
    QString Name();
    QString Password();

    QList<Dialog*> *dialogsList() const;
    Dialog *getDialog(QString) const;

     Q_INVOKABLE void addDialog(QString companion);
     Q_INVOKABLE void removeDialog(QString companion);

     Q_INVOKABLE void moveToBeginning(Dialog *);

signals:
     void dialogAdded(QString companion);
     void dialogRemoved(QString companion);

     void dialogAlreadtExists();
     void dialogsListChanged();

private:
    QHash<QString,Dialog*> *mHashDialogs;
    QList<Dialog*> *mListDialogs;
    QString mName;
    QString mPassword;

///*****************************************************************
private:
    friend QDataStream& operator << (QDataStream &, const User &);
    friend QDataStream& operator >> (QDataStream &, User &);
};

inline QDataStream& operator << (QDataStream &stream, const User &user)
{
    stream << user.mName << user.mPassword << user.mListDialogs->count();
    for(auto it = user.mListDialogs->begin(); it != user.mListDialogs->end(); it++)
    {
        stream <<  **it;
    }
    return stream;
}

inline QDataStream& operator >> (QDataStream &stream, User &user)
{
    int count;
    stream >>  user.mName >> user.mPassword >> count;

    user.mListDialogs = new QList<Dialog*>;
    user.mHashDialogs = new QHash<QString,Dialog*>;

    for(int i = 0; i < count; i++)
    {
        Dialog* d = new Dialog("",&user);
        stream >> *d;
        user.mListDialogs->append(d);
        user.mHashDialogs->insert(d->companion(),d);
    }
    return stream;
}
#endif // USER_H
