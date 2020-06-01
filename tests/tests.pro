include(gtest_dependency.pri)
include(SFML_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt
CONFIG+=c++11


QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS +=-fprofile-arcs -ftest-coverage
QMAKE_CFLAGS +=-fprofile-arcs -ftest-coverage
LIBS +=-lgcov

INCLUDEPATH += ../app

SOURCES += \
    ../app/effect_of_the_rune.cpp \
    ../app/game_draw.cpp \
    ../app/game_process.cpp \
    ../app/move_hero.cpp \
    ../app/pause_menu.cpp \
    ../app/randomize_rune_coordinates.cpp \
    ../app/take_rune.cpp \
    main.cpp

HEADERS += \
    ../app/cursors.h \
    ../app/game_objects.h \
    ../app/game_process.h \
    ../app/menu_bar.h \
    ../app/pause_menu.h \
    ../app/take_rune.h \
    ../app/tool_bar.h \
    game_process_test.h \
    move_hero_test.h \
    pause_menu_test.h \
    randomize_rune_coordinatest_test.h \
    take_rune_test.h


