TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    get_word.c \
    word_manage.c

HEADERS += \
    get_word.h \
    word_manage.h \
    word_manage_p.h

