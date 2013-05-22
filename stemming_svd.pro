#-------------------------------------------------
#
# Project created by QtCreator 2013-05-22T10:29:02
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = stemming_svd
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    stemming.cpp \
    libstemmer/libstemmer.c \
    runtime/utilities.c \
    runtime/api.c \
    src_c/stem_UTF_8_turkish.c \
    src_c/stem_UTF_8_swedish.c \
    src_c/stem_UTF_8_spanish.c \
    src_c/stem_UTF_8_russian.c \
    src_c/stem_UTF_8_romanian.c \
    src_c/stem_UTF_8_portuguese.c \
    src_c/stem_UTF_8_porter.c \
    src_c/stem_UTF_8_norwegian.c \
    src_c/stem_UTF_8_italian.c \
    src_c/stem_UTF_8_hungarian.c \
    src_c/stem_UTF_8_german.c \
    src_c/stem_UTF_8_french.c \
    src_c/stem_UTF_8_finnish.c \
    src_c/stem_UTF_8_english.c \
    src_c/stem_UTF_8_dutch.c \
    src_c/stem_UTF_8_danish.c \
    src_c/stem_KOI8_R_russian.c \
    src_c/stem_ISO_8859_2_romanian.c \
    src_c/stem_ISO_8859_1_swedish.c \
    src_c/stem_ISO_8859_1_spanish.c \
    src_c/stem_ISO_8859_1_portuguese.c \
    src_c/stem_ISO_8859_1_porter.c \
    src_c/stem_ISO_8859_1_norwegian.c \
    src_c/stem_ISO_8859_1_italian.c \
    src_c/stem_ISO_8859_1_hungarian.c \
    src_c/stem_ISO_8859_1_german.c \
    src_c/stem_ISO_8859_1_french.c \
    src_c/stem_ISO_8859_1_finnish.c \
    src_c/stem_ISO_8859_1_english.c \
    src_c/stem_ISO_8859_1_dutch.c \
    src_c/stem_ISO_8859_1_danish.c \
    text_to_svd.cpp

HEADERS += \
    stemming.hpp \
    include/libstemmer.h \
    libstemmer/modules_utf8.h \
    libstemmer/modules.h \
    libstemmer/libstemmer_c.in \
    runtime/header.h \
    runtime/api.h \
    src_c/stem_UTF_8_turkish.h \
    src_c/stem_UTF_8_swedish.h \
    src_c/stem_UTF_8_spanish.h \
    src_c/stem_UTF_8_russian.h \
    src_c/stem_UTF_8_romanian.h \
    src_c/stem_UTF_8_portuguese.h \
    src_c/stem_UTF_8_porter.h \
    src_c/stem_UTF_8_norwegian.h \
    src_c/stem_UTF_8_italian.h \
    src_c/stem_UTF_8_hungarian.h \
    src_c/stem_UTF_8_german.h \
    src_c/stem_UTF_8_french.h \
    src_c/stem_UTF_8_finnish.h \
    src_c/stem_UTF_8_english.h \
    src_c/stem_UTF_8_dutch.h \
    src_c/stem_UTF_8_danish.h \
    src_c/stem_KOI8_R_russian.h \
    src_c/stem_ISO_8859_2_romanian.h \
    src_c/stem_ISO_8859_1_swedish.h \
    src_c/stem_ISO_8859_1_spanish.h \
    src_c/stem_ISO_8859_1_portuguese.h \
    src_c/stem_ISO_8859_1_porter.h \
    src_c/stem_ISO_8859_1_norwegian.h \
    src_c/stem_ISO_8859_1_italian.h \
    src_c/stem_ISO_8859_1_hungarian.h \
    src_c/stem_ISO_8859_1_german.h \
    src_c/stem_ISO_8859_1_french.h \
    src_c/stem_ISO_8859_1_finnish.h \
    src_c/stem_ISO_8859_1_english.h \
    src_c/stem_ISO_8859_1_dutch.h \
    src_c/stem_ISO_8859_1_danish.h \
    text_to_svd.hpp

OTHER_FILES += \
    README.md \
    libstemmer/modules_utf8.txt \
    libstemmer/modules.txt \
    stop_symbols
