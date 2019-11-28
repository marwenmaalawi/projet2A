QT       += core gui network sql printsupport serialport charts \
            multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clients.cpp \
    connexion.cpp \
    gestion.cpp \
    login.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    promotions.cpp \
    smtp.cpp \
    statistiques.cpp

HEADERS += \
    clients.h \
    connexion.h \
    gestion.h \
    login.h \
    mail.h \
    mainwindow.h \
    notification.h \
    promotions.h \
    smtp.h \
    statistiques.h

FORMS += \
    gestion.ui \
    mail.ui \
    mainwindow.ui \
    statistiques.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    backgrounds.qrc

DISTFILES +=
