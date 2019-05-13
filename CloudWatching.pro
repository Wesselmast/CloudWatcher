#-------------------------------------------------
#
# Project created by QtCreator 2019-03-31T14:47:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CloudWatching
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
        _src/main.cpp \
        _src/renderingwindow.cpp \
        _src/generatedshape.cpp \
        _src/globals.cpp

HEADERS += \
        _include/math.h \
        _include/renderingwindow.h \
        _include/generatedshape.h \
        _include/globals.h

FORMS += \
        _form/renderingwindow.ui

MOC_DIR += _generated
OBJECTS_DIR += _generated


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    _form/resources.qrc
