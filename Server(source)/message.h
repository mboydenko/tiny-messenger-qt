#ifndef MESSAGE_H
#define MESSAGE_H

#include <QDataStream>

#include <QString>
#include <QObject>


class Message : public QObject
{
    Q_OBJECT
public:
    explicit  Message(QString,bool,QObject *parent = nullptr);
    //Сообщение
    QString message();
    //Пренадлежность собеседнику
    bool isMessageOfCompanion();
private:
    QString mMes;
    bool mComp;

//*********************************************************************
private:
    friend QDataStream& operator << (QDataStream& d, const Message& m);
    friend QDataStream& operator >> (QDataStream& d, Message& m);
};

inline QDataStream& operator << (QDataStream& d, const Message& m)
{
    d << m.mComp << m.mMes;
    return d;
}

inline QDataStream& operator >> (QDataStream& d, Message& m)
{
    d >> m.mComp >> m.mMes;
    return d;
}

#endif // MESSAGE_H
