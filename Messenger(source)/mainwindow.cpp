#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "registration.h"
#include "authorization.h"
#include "userwindow.h"

#include "dialog.h"

#include <QBoxLayout>
#include <QList>
#include <QThread>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


	client = new Client("127.0.0.1",22222,this);
    client->setObjectName("client");

    Q_ASSERT(QObject::connect
             (
                 client,        SIGNAL(signalUserReceived(const User&)),
                 this,          SLOT(setUser(const User&)))
             );

    client->connect();

    openAuthorization();
    setWindowTitle("Messenger");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUser(const User &user)
{
    openUserWindow(user);
}

void MainWindow::openRegistration()
{
   if(centerWidget != nullptr)
        delete centerWidget;

    centerWidget  = new Registration(this);

    setMinimumSize(centerWidget->size());
    setMaximumSize(centerWidget->size());

    Q_ASSERT(QObject::connect
             (
                 client,            SIGNAL(signalUserNameNotAvailable()),
                 centerWidget,      SLOT(slotInvalibleUser()))
             );
    Q_ASSERT(QObject::connect
             (
                 centerWidget,      SIGNAL(sendData(const QString&, const QString&)),
                 client,            SLOT(slotSendRegistrationData(const QString& , const QString&)))
             );

    Q_ASSERT(QObject::connect
             (
                 client,            SIGNAL(signalSuccessfulRegistration()),
                 centerWidget,      SLOT(slotSuccessfulRegistration()))
             );
    Q_ASSERT(QObject::connect
             (
                 client,            SIGNAL(signalServerNotAvailable()),
                 centerWidget,      SLOT(serverNotAvailable()))
             );

    ui->verticalLayout->addWidget(centerWidget);

}

void MainWindow::openAuthorization()
{
    if(centerWidget != nullptr)
        delete centerWidget;


    centerWidget = new Authorization(this);

	setFixedSize(centerWidget->size());

    Q_ASSERT(QObject::connect
             (
                 centerWidget,      SIGNAL(sendData(const QString&, const QString&)),
                 client,            SLOT(slotSendAuthorizationData(const QString&, const QString&)))
             );
    Q_ASSERT(QObject::connect
             (
                 client,            SIGNAL(signalInvalidData()),
                 centerWidget,      SLOT(invalidData()))
             );
    Q_ASSERT(QObject::connect
             (
                 client,            SIGNAL(signalServerNotAvailable()),
                 centerWidget,      SLOT(serverNotAvailable()))
             );


	ui->verticalLayout->addWidget(centerWidget);
}

void MainWindow::openUserWindow(const User &user)
{
    if(centerWidget != nullptr)
        delete centerWidget;

    centerWidget = new UserWindow(user,this);

    setMinimumSize(QSize(680,480));
    setMaximumSize(QSize(10000,10000));

    Q_ASSERT(QObject::connect
             (
                 centerWidget,      SIGNAL(signalExit()),
                 client,            SLOT(slotExitUser()))
             );

    Q_ASSERT(QObject::connect
             (
                 centerWidget,      SIGNAL(signalExit()),
                 this,              SLOT(changeUser()))
             );

    Q_ASSERT(QObject::connect
             (
                 centerWidget,      SIGNAL(signalAddDialog(const QString&)),
                 client,            SLOT(slotAddDialog(const QString&)))
             );
    Q_ASSERT(QObject::connect
             (
                 centerWidget,      SIGNAL(signalDeleteDialog(const QString&)),
                 client,            SLOT(slotDeleteDialog(const QString&)))
             );
    Q_ASSERT(QObject::connect
             (
                 centerWidget,      SIGNAL(signalSendMessage(const QString&, const QString&)),
                 client,            SLOT(slotSendMessage(const QString&, const QString&)))
             );
    Q_ASSERT(QObject::connect
             (
                 client,            SIGNAL(signalReceiveMessage(const QString&,const QString&,const QString&)),
                 centerWidget,      SLOT(slotAddMessage(const QString&,const QString&,const QString&)))
             );
    Q_ASSERT(QObject::connect
             (
                 client,            SIGNAL(signalAddDialog(const QString&)),
                 centerWidget,      SLOT(slotAddDialog(const QString&)))
             );

    Q_ASSERT(QObject::connect
             (
                 client,            SIGNAL(signalDeleteDialog(const QString&)),
                 centerWidget,      SLOT(slotDeleteDialog(const QString&)))
             );


    ui->verticalLayout->addWidget(centerWidget);
}

void MainWindow::changeUser()
{
    openAuthorization();
}
