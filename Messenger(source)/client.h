#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

#include "user.h"

class Client  : public QObject
{
    Q_OBJECT

public:
    explicit Client(const QString& hostName, const quint16& port,QObject* parent = nullptr);
public:
    void setHostName(const QString&);
    void setPort(const quint16&);
    void connect();

private:
    void proccesData(QDataStream &);
    void reconnect();

    void processReceivedMessage(const QString &mes, const QString &sender, const QString &destination);

    void sendToServer(const QByteArray*);

    QByteArray putInByteArray(const QString& key, const QString&, const QString&, const QString&);
    QByteArray putInByteArray(const QString& key, const QString&, const QString&);
    QByteArray putInByteArray(const QString& key, const QString&);
    QByteArray putInByteArray(const QString& key);

public slots:  

    void slotReadyRead();
    void slotConnected();
    void slotError(QAbstractSocket::SocketError);

    void slotExitUser();

    void slotSendRegistrationData(const QString& login, const QString& password);
    void slotSendAuthorizationData(const QString& login, const QString& password);

    void slotAddDialog(const QString& title);
    void slotDeleteDialog(const QString&);

    //void slotSendMessage(const QString& message, const QString& sender, const QString& destination);
    void slotSendMessage(const QString& mes, const QString& destination);

signals:
    void signalInvalidData();
    void signalUserNameNotAvailable();
    void signalSuccessfulRegistration();
    void signalUserReceived(const User&);
    void signalUserNotFound();
    void signalServerNotAvailable();

    void signalReceiveMessage(const QString& mes, const QString& sender, const QString& destination);
    void signalAddDialog(const QString&);
    void signalDeleteDialog(const QString&);
private:
    User *user;
    quint16 m_port;
    QTcpSocket *m_socket;
    QString m_hostName;
};

#endif // CLIENT_H
