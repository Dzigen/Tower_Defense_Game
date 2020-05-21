include(gtest_dependency.pri)

CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS +=-fprofile-arcs -ftest-coverage
QMAKE_CFLAGS +=-fprofile-arcs -ftest-coverage
LIBS += -lgcov -lsfml-audio -lsfml-system -lsfml-network -lsfml-window -lsfml-graphics

INCLUDEPATH += ../app
