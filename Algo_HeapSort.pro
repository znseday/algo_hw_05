TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lstdc++fs

SOURCES += \
        main.cpp \
        moveable.cpp \
        sort.cpp

HEADERS += \
    itask.h \
    moveable.h \
    sort.h \
    test_generator.h \
    tester.h
