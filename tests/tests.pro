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

SOURCES += \
    ../app/game_draw.cpp \
    ../app/game_process.cpp \
    ../app/initialize_game.cpp \
    ../app/main.cpp \
    ../app/pause_menu.cpp

HEADERS += \
    ../app/cursors.h \
    ../app/game_objects.h \
    ../app/game_process.h \
    ../app/main.h \
    ../app/menu_bar.h \
    ../app/pause_menu.h \
    ../app/tool_bar.h


