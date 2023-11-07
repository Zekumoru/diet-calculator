TEMPLATE = app
TARGET = diet-calculator


QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    data/diet.cpp \
    main.cpp \
    widgets/dietcard.cpp \
    widgets/inputwidget.cpp

HEADERS += \
    data/diet.h \
    utils/units.h \
    widgets/dietcard.h \
    widgets/inputwidget.h
