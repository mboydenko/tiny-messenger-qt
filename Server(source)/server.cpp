#include "server.h"

#include <QDataStream>
#include <QFile>

Server::Server(quint16 port, QObject *parent) : QObject(parent)
{
    m_port = port;
    m_users = new QList<User*>;
    m_activeUserSockets = new QHash<QString,QList<QTcpSocket*>*>;
    load();
}

void Server::setPort(quint16 _port)
{
    m_port = _port;
}

void Server::start()
{
    m_server = new QTcpServer(this);

    if(!m_server->listen(QHostAddress::Any,m_port))
    {
        qDebug() << "SERVER ERROR " << "Unable to start the server: "
                 << m_server->errorString();
    }
    else
    {
        Q_ASSERT(QObject::connect(m_server,SIGNAL(newConnection()), this,SLOT(slotNewConnection())));
        qDebug() << "SERVER IS STARTED" << "\n" << "PORT: " << m_port;
    }
}

void Server::stop()
{
    save();
    delete m_server;
}

void Server::load()
{
    QFile file("db.bin");
    if(file.open(QFile::ReadOnly))
    {
        while(!file.atEnd())
        {
            QDataStream stream(&file);
            User* usr = new User();
            stream >> *usr;
            addUser(usr);
        }
        file.close();
    }
}

void Server::save()
{
   QFile file("db.bin");
   if(file.open(QFile::WriteOnly))
   {
       QDataStream stream(&file);
       for(auto it = m_users->begin(); it != m_users->end(); it++)
           stream << **it;

       file.close();
   }
}


bool Server::removeUserSocket(QString name, QTcpSocket *socket)
{
    if(QList<QTcpSocket*> *list = m_activeUserSockets->value(name)){
        list->removeOne(socket);
        qDebug() << "SYSTEM INFO: SOCKET " << socket << " EXIT FROM ACCOUNT " << name;
        return true;
    }
    return false;
}

bool Server::addUserSocket(QString user, QTcpSocket *socket)
{
    QList<QTcpSocket*> *list = m_activeUserSockets->value(user);
    if(list == nullptr)
    {
        list = new QList<QTcpSocket*>;
        list->append(socket);
        m_activeUserSockets->insert(user,list);
    }
    list->append(socket);

    qDebug() << "SYSTEM INFO: SOCKET: " << socket << "LOGINNED IN AS " << user;
    return true;
}

bool Server::addUser(QString name, QString password)
{
     User* user = new User(name,password);
     return addUser(user);
}

bool Server::addUser(User *usr)
{
    if(getUser(usr->Name()))
    {
        delete usr;
        return false;
    }
    else {

        m_users->append(usr);
        QList<QTcpSocket*> *sockets = new QList<QTcpSocket*>;
        m_activeUserSockets->insert(usr->Name(),sockets);

        qDebug() << "SYSTEM INFO: ACCOUNT " << usr->Name() << " WAS CREATED";

        return true;
    }
}

bool Server::removeUser(QString name)
{
    if(User *user = getUser(name))
    {
        m_users->removeOne(user);
        delete user;

        qDebug() << "SYSTEM INFO: ACCOUNT " << name << " WAS CREATED";

        return true;
    }
    else
        return false;
}

QByteArray Server::putInByteArray(QString key, User *user)
{
    QByteArray arr;
    QDataStream stream(&arr,QIODevice::WriteOnly);

    stream << quint16(0) << key << *user;
    stream.device()->seek(0);
    stream << quint16(arr.size() - sizeof (quint16));

    return arr;
}

QByteArray Server::putInByteArray(QString key, QString mes, QString sender, QString destination)
{
    QByteArray arr;
    QDataStream stream(&arr,QIODevice::WriteOnly);
    stream << quint16(0) << key << mes << sender << destination;
    stream.device()->seek(0);
    stream << quint16(arr.size() - sizeof (quint16));
    return arr;
}

QByteArray Server::putInByteArray(QString key, QString name)
{
    QByteArray arr;
    QDataStream stream(&arr,QIODevice::WriteOnly);
    stream << quint16(0) << key << name;
    stream.device()->seek(0);
    stream << quint16(arr.size() - sizeof (quint16));
    return arr;
}

QByteArray Server::putInByteArray(QString key)
{
    QByteArray arr;
    QDataStream stream(&arr,QIODevice::WriteOnly);
    stream << quint16(0) << key;
    stream.device()->seek(0);
    stream << quint16(arr.size() - sizeof (quint16));
    return arr;
}


void Server::sendToClient(QTcpSocket *socket, QByteArray *arrByte)
{
    socket->write(*arrByte);

    //qDebug() << "SYSTEM INFO: DATA SENT TO CLIENT SOCKET" << socket;
}

void Server::sendToClients(QString username, QByteArray *arrBlock)
{
    QList<QTcpSocket*> *_sockets = sockets(username);
    if(!_sockets->isEmpty() && _sockets != nullptr)
        sendToClients(_sockets, arrBlock);
    delete _sockets;
}

void Server::sendToClients(QList<QTcpSocket *> *sockets, QByteArray *arrBlock)
{
    if(!sockets->isEmpty() && sockets != nullptr)
    {
        for (auto it = sockets->begin(); it != sockets->end() ; it++)
        {
            sendToClient(*it,arrBlock);
        }
    }
}

void Server::disconnectClients(QString name)
{
    QList<QTcpSocket*> *sockets = m_activeUserSockets->value(name);
    disconnectClients(sockets);
}

void Server::disconnectClients(QList<QTcpSocket*>* sockets)
{
    for (auto it = sockets->begin(); it != sockets->end(); it++)
    {
        QTcpSocket *socket = *it;
        sockets->removeOne(socket);
        disconnectClient(socket);
    }
}

void Server::disconnectClient(QTcpSocket *socket)
{
    socket->disconnect();
}


void Server::receivedMessageFromClient(QString mes, QString sender, QString destination)
{
    User *user1 = getUser(sender);
    User *user2 = getUser(destination);

    if(user1)
    {
        if(Dialog *dialog = user1->getDialog(destination))
        {
            dialog->addMessage(mes,false);
        }
        else {
            user1->addDialog(destination);
            dialog = user1->getDialog(destination);
            dialog->addMessage(mes,false);
        }
    }

    if(user2)
    {
        if(Dialog *dialog = user2->getDialog(sender))
        {
            dialog->addMessage(mes,true);
        }
        else {
            user2->addDialog(sender);
            dialog = user2->getDialog(sender);
            dialog->addMessage(mes,true);
        }
    }
}


void Server::slotNewConnection()
{
    QTcpSocket *socket = m_server->nextPendingConnection();

    Q_ASSERT(QObject::connect(socket,SIGNAL(disconnected()),this,SLOT(slotSocketDisconnected())));
    Q_ASSERT(QObject::connect(socket,SIGNAL(disconnected()),socket,SLOT(deleteLater())));
    Q_ASSERT(QObject::connect(socket,SIGNAL(readyRead()),this,SLOT(slotReadClient())));

    qDebug() << "SYSTEM INFO: SOCKET " << socket << " IS CONNECTED";

}

void Server::slotSocketDisconnected()
{
    QTcpSocket *socket = reinterpret_cast<QTcpSocket*>(sender());
    if(User *user = getUser(socket))
    {
        removeUserSocket(user->Name(),socket);
    }
    qDebug() << "SYSTEM INFO: SOCKET " << socket << " DISCONNECTED";
}

void Server::slotReadClient()
{

    QTcpSocket *clientSocket = reinterpret_cast<QTcpSocket*>(sender());
    quint16 nextBlockSize = 0;
    QDataStream in(clientSocket);
    QString key;

    //qDebug() << "SYSTEM INFO: GOT DATA FROM CLIENT " << "SOCKET: "<< clientSocket;

    for (;;)
    {
        if(!nextBlockSize)
        {
            if(clientSocket->bytesAvailable() < sizeof (quint16))
            {
                break;
            }
            in >> nextBlockSize;
        }

        if (clientSocket->bytesAvailable() < nextBlockSize)
        {
            break;
        }
        in >> key;

        if(key == "<MESSAGE>")
        {
            QString mes;
            QString sender;
            QString destination;
            in >> mes >> sender >> destination;

            receivedMessageFromClient(mes,sender,destination);
            save();

            QList<QTcpSocket*> *senderSockets = otherSockets(sender,clientSocket);
            QList<QTcpSocket*> *destinationSockets = sockets(destination);

            QByteArray arrBlock = putInByteArray(key,mes,sender,destination);

            if(!destinationSockets->isEmpty())
                sendToClients(destinationSockets,&arrBlock);

            if(!senderSockets->isEmpty())
                sendToClients(senderSockets,&arrBlock);

            delete senderSockets;
            delete destinationSockets;
        }

        if(key == "<AUTHORIZATION_DATA>")
        {
            QString login;
            QString password;
            in >> login >> password;
            if(User* user = getUser(login,password))
            {
                QByteArray arrBlock = putInByteArray("<USER>",user);
                addUserSocket(login,clientSocket);
                sendToClient(clientSocket,&arrBlock);
            }
            else
            {
                QByteArray arrBlock = putInByteArray("<AUTHORIZATION_INVALID_DATA>");
                sendToClient(clientSocket,&arrBlock);
            }
        }

        if(key == "<REGISTRATION_DATA>")
        {
            QString login;
            QString password;

            in >> login >> password;
            if(addUser(login,password))
            {
                save();

                QByteArray arrBlock = putInByteArray("<REGISTRATION_COMPLETED_SUCCESSFULLY>");
                sendToClient(clientSocket,&arrBlock);
            }
            else {
                QByteArray arrBlock = putInByteArray("<REGISTRATION_ERROR_USERNAME_NOT_AVAILABLE>");
                sendToClient(clientSocket,&arrBlock);
            }

        }

        if(key == "<ADD_DIALOG>")
        {
            QString dialog;
            QString user;

            in >> dialog;
            user = getUserName(clientSocket);

            if(dialog != user)
            {
                if(getUser(dialog))
                {
                    if(!dialogOfUser(user,dialog))
                    {
                        QByteArray arrBlock = putInByteArray("<ADD_DIALOG>", dialog);
                        addDialog(user,dialog);
                        save();

                        sendToClients(user,&arrBlock);
                    }
                    else
                    {
                        QByteArray arrBloock = putInByteArray("<>");
                    }
                }
                else
                {
                    QByteArray arrBlock = putInByteArray("<USER_NOT_FOUND>");
                    sendToClient(clientSocket,&arrBlock);
                }
            }
        }

        if(key == "<REMOVE_DIALOG>")
        {
            QString dialog;
            QString user;

            in >> dialog;
            user = getUserName(clientSocket);
            QList<QTcpSocket*> *_sockets = otherSockets(clientSocket);
            if(removeDialog(user,dialog))
            {
                save();

                QByteArray arrBlock = putInByteArray("<REMOVE_DIALOG>",dialog);
                sendToClients(_sockets,&arrBlock);
            }
            delete _sockets;
        }

        if(key == "<EXIT_USER>")
        {
            QString name = getUserName(clientSocket);
            removeUserSocket(name,clientSocket);
        }
    }
}


User *Server::getUser(QString name)
{
    if(!m_users->isEmpty())
    {
        for (auto it = m_users->begin();it != m_users->end(); it++)
        {
           User *user = *it;
           if(user->Name() == name)
               return user;
        }
    }
    return nullptr;
}

User *Server::getUser(QString login, QString password)
{
    if(User *user = getUser(login))
    {
        if(user->Password() == password)
            return user;
        else return nullptr;
    }
    else return nullptr;
}

User *Server::getUser(QTcpSocket *socket)
{
    if(!m_activeUserSockets->isEmpty())
    {
        QList<QString> keys = m_activeUserSockets->keys();
        for (auto it = keys.begin(); it != keys.end(); it++)
        {
            QList<QTcpSocket*> *sockets = m_activeUserSockets->value(*it);
            for (auto it2 = sockets->begin(); it2 != sockets->end(); it2++)
            {
                if(socket == *it2)
                    return getUser(*it);
            }
        }
    }
    return nullptr;
}

QString Server::getUserName(QTcpSocket *socket)
{
    User *user = getUser(socket);
    return user->Name();
}


bool Server::addDialog(QString user, QString dialog)
{
    User* _user = getUser(user);
    return addDialog(_user,dialog);
}

bool Server::addDialog(User *user, QString dialog)
{
    if(user->getDialog(dialog))
    {
        return false;
    }
    else {
        user->addDialog(dialog);
        return true;
    }
}

bool Server::removeDialog(QString user, QString dialog)
{
    if(User *_user = getUser(user))
    {
        return removeDialog(_user,dialog);
    }

    return false;
}

bool Server::removeDialog(User *user, QString dialog)
{
    if(user->getDialog(dialog))
    {
        user->removeDialog(dialog);

        qDebug() << "SYSTEM INFO:" << user->Name() << "DELETED DIALOG WITH" << getUser(dialog)->Name();
        return true;
    }

    return false;
}


bool Server::dialogOfUser(QString user, QString dialog)
{
    User *_user = getUser(user);
    return dialogOfUser(_user,dialog);
}

bool Server::dialogOfUser(User *user, QString dialog)
{
    if(user->getDialog(dialog))
        return true;
    else {
        return false;
    }
}


QList<QTcpSocket *> *Server::sockets(QString name)
{
    if(QList<QTcpSocket*> *_sockets = m_activeUserSockets->value(name))
    {
        QList<QTcpSocket*> *_buf = new QList<QTcpSocket*>;
        for (auto it = _sockets->begin(); it != _sockets->end(); it++)
        {
            _buf->append(*it);
        }
        return _buf;
    }
    return nullptr;
}

QList<QTcpSocket *> *Server::otherSockets(QTcpSocket *socket)
{
    QString name = getUserName(socket);
    return otherSockets(name, socket);
}

QList<QTcpSocket *> *Server::otherSockets(QString name, QTcpSocket *socket)
{
    QList<QTcpSocket*> *_sockets = sockets(name);
    QList<QTcpSocket*> *_otherSockets = new QList<QTcpSocket*>;
    for (auto it =  _sockets->begin(); it != _sockets->end(); it++)
    {
        if(socket == *it)
            continue;
        _otherSockets->append(*it);
    }
    delete _sockets;
    return _otherSockets;
}
