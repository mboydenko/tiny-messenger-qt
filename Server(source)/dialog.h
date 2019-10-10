#ifndef DIALOG_H
#define DIALOG_H


#include <QList>
#include <QObject>
#include <QString>

#include "message.h"

class Dialog : public QObject
{
    Q_OBJECT
public:
    explicit Dialog(QString companion, QObject *parent = nullptr);
    ~Dialog();
    //Служит для добавления сообщения(Сообщение, Флаг пренадлежности собеседнику)
    void addMessage(QString str, bool ofCompanion);

    //Собеседник
    QString companion();
    //Массив сообщений
    QList<Message*>* messages() const;

signals:
    void dialogChanged();
private:
    QString mCompanion;
    QList<Message*> *mMessages;


//**********************************************************************************
private:
    friend QDataStream& operator << (QDataStream&, const Dialog&);
    friend QDataStream& operator >> (QDataStream&, Dialog&);
};

inline QDataStream& operator << (QDataStream& stream, const Dialog& dialog)
{
    stream << dialog.mCompanion << dialog.messages()->count();
    for(auto it = dialog.mMessages->begin(); it != dialog.mMessages->end(); it++)
        stream << **it;
    return stream;
}

inline QDataStream& operator >> (QDataStream& stream, Dialog &dialog)
{
    int count;
    stream >> dialog.mCompanion >> count;
    dialog.mMessages = new QList<Message*>;
    for(int i = 0; i < count; i++)
    {
        Message* mes = new Message("",0,&dialog);
        stream >> *mes;
        dialog.mMessages->append(mes);
    }
    return stream;
}

#endif // DIALOG_H
