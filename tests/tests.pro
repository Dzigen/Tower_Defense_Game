include(gtest_dependency.pri)

CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS +=-fprofile-arcs -ftest-coverage
QMAKE_CFLAGS +=-fprofile-arcs -ftest-coverage
LIBS += -lgcov

#sfml
ROOT = $${PWD}/../external
LIBS        += -L"$${ROOT}/SFML/lib/debug/" -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d


INCLUDEPATH += ../app

SOURCES += \
    ../app/main.cpp
