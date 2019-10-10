#include "message.h"

Message::Message(const QString &mes,
                 const bool &com,
                 QObject* parent)
    : QObject (parent)
{
    mMes = mes;
    mComp = com;
}

bool Message::isMessageOfCompanion() const
{
    return mComp;
}

QString Message::message() const
{
    return mMes;
}
