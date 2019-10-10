#ifndef SERVER_H
#define SERVER_H

#include <QObject>

#include <QHash>
#include <QList>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>

#include "user.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(quint16 port, QObject *parent = nullptr);


public:
    void start();
    void stop();
    void load();
    void save();

private:
    bool addUser(QString, QString);
    bool addUser(User*);

    bool removeUser(QString);
    bool removeUser(User*);

    void addUserSockets(QString user);
    void addSocketToUserSokets(QString user, QTcpSocket* socket);

    bool removeUserSocket(QString,QTcpSocket*);
    bool addUserSocket(QString,QTcpSocket*);

    void sendToClient(QTcpSocket *socket, QByteArray*);
    void sendToClients(QList<QTcpSocket*>*,QByteArray*);
    void sendToClients(QString username, QByteArray*);

    void disconnectClients(QString username);
    void disconnectClients(QList<QTcpSocket*>*);
    void disconnectClient(QTcpSocket*);

    void receivedMessageFromClient(QString, QString, QString);

    User *getUser(QString);
    User *getUser(QString,QString);
    User *getUser(QTcpSocket*);
    QString getUserName(QTcpSocket*);


    bool addDialog(QString user, QString dialog);
    bool addDialog(User* user, QString dialog);
    bool removeDialog(QString user, QString dialog);
    bool removeDialog(User* user, QString dialog);

    bool dialogOfUser(QString user, QString dialog);
    bool dialogOfUser(User* user, QString dialog);

    QList<QTcpSocket*> *sockets(QString);
    QList<QTcpSocket*> *otherSockets(QTcpSocket*);
    QList<QTcpSocket*> *otherSockets(QString,QTcpSocket*);

    QByteArray putInByteArray(QString key, User* user);
    QByteArray putInByteArray(QString key, QString mes, QString sender, QString destination);
    QByteArray putInByteArray(QString key, QString name);
    QByteArray putInByteArray(QString key);

    void setPort(quint16);

signals:

public slots:

    void slotReadClient();
    void slotNewConnection();
    void slotSocketDisconnected();

private:
    quint16 m_port;

    QTcpServer *m_server;
    QList<User*>*m_users;
    QHash<QString, QList<QTcpSocket*>*>* m_activeUserSockets;
};

#endif // SERVER_H
