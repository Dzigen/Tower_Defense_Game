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
    ../app/move_hero.cpp \
    ../app/randomize_rune_coordinates.cpp \
    ../app/take_rune.cpp \
    ../app/update_spawn_rune.cpp \
    main.cpp

HEADERS += \
    ../app/cursors.h \
    ../app/game_objects.h \
    ../app/menu_bar.h \
    ../app/take_rune.h \
    ../app/tool_bar.h \
    ../app/update_spawn_rune.h \
    move_hero_test.h \
    randomize_rune_coordinatest_test.h \
    take_rune_test.h \
    update_spawn_rune_test.h


