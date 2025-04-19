QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    qoptionswidget.cpp \
    qplotoptionswidget.cpp \
    qspectrogram.cpp \
    qtimeseriesplot.cpp \
    qvariableplot.cpp

HEADERS += \
    fftw3.h \
    mainwindow.h \
    qcustomplot.h \
    qoptionswidget.h \
    qplotoptionswidget.h \
    qspectrogram.h \
    qtimeseriesplot.h \
    qvariableplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
