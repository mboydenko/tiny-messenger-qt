#include <QTextEdit>
#include <QDebug>
#include <QMessageBox>
#include <QMetaObject>

#include "client.h"

Client::Client(const QString& hostName,
               const quint16& port,
               QObject *parent) :
               QObject (parent)
{
    m_hostName = hostName;
    m_port = port;
}

void Client::setHostName(const QString& hostName)
{
    m_hostName = hostName;
}

void Client::setPort(const quint16 &port)
{
    m_port = port;
}

void Client::proccesData (QDataStream &data)
{
    quint16 mBlockSize = 0;
    QString key;
    for (;;) {
        if(!mBlockSize)
        {
            if(m_socket->bytesAvailable() < sizeof(quint16))
                break;
            data >> mBlockSize;
        }

        if(m_socket->bytesAvailable() < mBlockSize)
            break;

        data >> key;

        if(key == "<USER>")
        {
            User *user = new User(this);
            data >> *user;
            this->user = user;

            emit signalUserReceived(*user);
            return;
        }

        if(key == "<REMOVE_DIALOG>")
        {
            QString dialog;
            data >> dialog;
            user->removeDialog(dialog);
            emit signalDeleteDialog(dialog);
            return;
        }

        if(key == "<ADD_DIALOG>")
        {
            QString dialog;
            data >> dialog;
            user->addDialog(dialog);
            emit signalAddDialog(dialog);

            return;
        }

        if(key == "<MESSAGE>")
        {
            QString mes;
            QString destination;
            QString pSender;
            data >> mes >> pSender >>destination;

            processReceivedMessage(mes,pSender,destination);
            emit signalReceiveMessage(mes,pSender,destination);
            return;
        }

        if(key == "<AUTHORIZATION_INVALID_DATA>")
        {
            emit signalInvalidData();
            return;
        }

        if(key == "<REGISTRATION_ERROR_USERNAME_NOT_AVAILABLE>")
        {
            emit signalUserNameNotAvailable();
            return;
        }

        if(key == "<REGISTRATION_COMPLETED_SUCCESSFULLY>"){
            emit signalSuccessfulRegistration();
            return;
        }

        if(key == "<USER_NOT_FOUND>")
        {
            emit signalUserNotFound();
            return;
        }
     }
}

void Client::connect()
{

    m_socket = new QTcpSocket(this);

    m_socket->connectToHost(m_hostName,m_port);

    Q_ASSERT(QObject::connect(m_socket,SIGNAL(connected()),this,SLOT(slotConnected())));
    Q_ASSERT(QObject::connect(m_socket,SIGNAL(readyRead()),this,SLOT(slotReadyRead())));
    Q_ASSERT(QObject::connect(m_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(slotError(QAbstractSocket::SocketError))));
    Q_ASSERT(QObject::connect(m_socket,SIGNAL(disconnected()),m_socket,SLOT(deleteLater())));
}

void Client::reconnect()
{
    connect();
}

void Client::processReceivedMessage(const QString &mes, const QString &sender, const QString& destination)
{
    if(sender == user->Name())
    {
        if(Dialog* dialog = user->getDialog(destination))
        {
            dialog->addMessage(mes,false);
        }
        else
        {
            user->addDialog(destination);
            dialog = user->getDialog(destination);
            dialog->addMessage(mes,false);
        }
    }

    else if(destination == user->Name())
    {
        if(Dialog* dialog = user->getDialog(sender))
        {           
            dialog->addMessage(mes,true);
        }
        else
        {
            user->addDialog(sender);
            dialog = user->getDialog(sender);
            dialog->addMessage(mes,true);
        }
    }
}

void Client::sendToServer(const QByteArray *data)
{
    m_socket->write(*data);
}

void Client::slotExitUser()
{
    delete user;
    if(m_socket->state() == QTcpSocket::ConnectedState)
    {
        QByteArray arrBlock = putInByteArray("<EXIT_USER>");
        m_socket->write(arrBlock);
    }
}


void Client::slotSendMessage(const QString &mes, const QString &destination)
{
    if(m_socket->state() == QTcpSocket::ConnectedState)
    {
        if(Dialog *d = user->getDialog(destination))
            d->addMessage(mes,false);

        QByteArray arrBlock = putInByteArray("<MESSAGE>",mes,user->Name(),destination);
        m_socket->write(arrBlock);
    }
}

void Client::slotAddDialog(const QString& title)
{
    if(m_socket->state() == QTcpSocket::ConnectedState)
    {
        QByteArray arrBlock = putInByteArray("<ADD_DIALOG>",title);
        m_socket->write(arrBlock);
    }
}

void Client::slotDeleteDialog(const QString& title)
{
    user->removeDialog(title);
    if(m_socket->state() == QTcpSocket::ConnectedState)
    {
        QByteArray arrBlock = putInByteArray("<REMOVE_DIALOG>",title);
        m_socket->write(arrBlock);
    }
}

void Client::slotSendRegistrationData(const QString& login, const QString& password)
{
    if(m_socket->state() == QTcpSocket::ConnectedState)
    {
        QByteArray arrBlock = putInByteArray("<REGISTRATION_DATA>", login, password);
        m_socket->write(arrBlock);
    }
}

void Client::slotSendAuthorizationData(const QString& login, const QString& password)
{
    if(m_socket->state() == QTcpSocket::ConnectedState)
    {
        QByteArray arrBlock = putInByteArray("<AUTHORIZATION_DATA>",login,password);
        m_socket->write(arrBlock);
    }
}


QByteArray Client::putInByteArray(const QString& key, const QString& data1, const QString& data2, const QString& data3)
{
    QByteArray arr;
    QDataStream stream(&arr,QIODevice::WriteOnly);;
    stream << quint16(0) << key << data1 << data2 << data3;
    stream.device()->seek(0);
    stream << quint16(arr.size() - sizeof (quint16));
    return arr;
}

QByteArray Client::putInByteArray(const QString& key, const QString& data1, const QString& data2)
{
    QByteArray arr;
    QDataStream stream(&arr,QIODevice::WriteOnly);;
    stream << quint16(0) << key << data1 << data2;
    stream.device()->seek(0);
    stream << quint16(arr.size() - sizeof (quint16));
    return arr;
}

QByteArray Client::putInByteArray(const QString& key, const QString& data)
{
    QByteArray arr;
    QDataStream stream(&arr,QIODevice::WriteOnly);
    stream << quint16(0) << key << data;
    stream.device()->seek(0);
    stream << quint16(arr.size() - sizeof (quint16));
    return arr;
}

QByteArray Client::putInByteArray(const QString& key)
{
    QByteArray arr;
    QDataStream stream(&arr,QIODevice::WriteOnly);
    stream << quint16(0) << key;
    stream.device()->seek(0);
    stream << quint16(arr.size() - sizeof (quint16));
    return arr;
}


void Client::slotReadyRead()
{
    QDataStream stream(m_socket);
    proccesData(stream);
}

void Client::slotConnected()
{
    qDebug() << "Succese connection";
}

void Client::slotError(QAbstractSocket::SocketError)
{
    qDebug() << "ERROR";

    if(parent()->findChild<QObject*>("UserWindow"))
    {
        QMessageBox box;
        box.setModal(true);
        box.setIcon(QMessageBox::Critical);
        box.setWindowTitle("Разрыв соединения");
        box.setText("Соединение с сервером разорвано");
        box.setStandardButtons(QMessageBox::Ok);

        int ret = box.exec();
        switch (ret)
        {
            case QMessageBox::Ok:
                QMetaObject::invokeMethod(parent(),"openAuthorization");
                break;
            default:
                break;
        }
    }

    reconnect();
}
