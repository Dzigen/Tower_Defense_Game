include(gtest_dependency.pri)
include(SFML_dependency.pri)

CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS +=-fprofile-arcs -ftest-coverage
QMAKE_CFLAGS +=-fprofile-arcs -ftest-coverage
LIBS += -lgcov

INCLUDEPATH += ../app

SOURCES += \
    ../app/main.cpp