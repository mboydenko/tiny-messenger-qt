#-------------------------------------------------
#
# Project created by QtCreator 2019-08-22T10:46:47
#
#-------------------------------------------------

QT       += core gui network svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Messanger
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        ChatList/chatlist.cpp \
        ChatList/chatlistblock.cpp \
        ChatList/widgetchatlist.cpp \
        Other/buttonimage.cpp \
        addnewdialogwindow.cpp \
        authorization.cpp \
        chatRegionWidget/chatblock.cpp \
        chatRegionWidget/chatregion.cpp \
        chatRegionWidget/chatregion_scene.cpp \
        chatbox.cpp \
        client.cpp \
        dialog.cpp \
        dialogsbox.cpp \
        main.cpp \
        mainwindow.cpp \
        message.cpp \
        registration.cpp \
        user.cpp \
        userbox.cpp \
        userwindow.cpp

HEADERS += \
        ChatList/chatlist.h \
        ChatList/chatlistblock.h \
        ChatList/widgetchatlist.h \
        Other/buttonimage.h \
        addnewdialogwindow.h \
        authorization.h \
        chatRegionWidget/chatblock.h \
        chatRegionWidget/chatregion.h \
        chatRegionWidget/chatregion_scene.h \
        chatbox.h \
        client.h \
        dialog.h \
        dialogsbox.h \
        mainwindow.h \
        message.h \
        registration.h \
        user.h \
        userbox.h \
        userwindow.h

FORMS += \
        addnewdialogwindow.ui \
        authorization.ui \
        chatbox.ui \
        dialogitem.ui \
        dialogsbox.ui \
        mainwindow.ui \
        registration.ui \
        userbox.ui \
        userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc.qrc

DISTFILES +=

SUBDIRS += \
    ChatList/ChatList.pro
