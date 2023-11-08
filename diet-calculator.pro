TEMPLATE = app
TARGET = diet-calculator


QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    data/diet.cpp \
    main.cpp \
    utils/health.cpp \
    utils/units.cpp \
    widgets/dietcard.cpp \
    widgets/dietlist.cpp \
    widgets/inputwidget.cpp \
    widgets/mainwindow.cpp

HEADERS += \
    data/diet.h \
    utils/health.h \
    utils/units.h \
    widgets/dietcard.h \
    widgets/dietlist.h \
    widgets/inputwidget.h \
    widgets/mainwindow.h
