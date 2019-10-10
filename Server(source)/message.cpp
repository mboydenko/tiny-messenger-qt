#include "message.h"

Message::Message(QString mes, bool com, QObject* parent) : QObject (parent)
{
    mMes = mes;
    mComp = com;
}

bool Message::isMessageOfCompanion()
{
    return mComp;
}

QString Message::message()
{
    return mMes;
}
