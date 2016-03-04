TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    word_manage.c \
    get_word.c

HEADERS += \
    word_manage.h \
    get_word.h \
    word_manage_p.h

