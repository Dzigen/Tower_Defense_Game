include(SFML_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG+=c++11

SOURCES += \
        effect_of_the_rune.cpp \
        game_draw.cpp \
        game_process.cpp \
        main.cpp \
        move_hero.cpp \
        pause_menu.cpp \
        randomize_rune_coordinates.cpp \
        take_rune.cpp

HEADERS += \
    cursors.h \
    game_objects.h \
    game_process.h \
    main.h \
    menu_bar.h \
    pause_menu.h \
    take_rune.h \
    tool_bar.h

QMAKE_CFLAGS += -Wall -Wextra -Werror -std=c++11
QMAKE_LFLAGS +=  -std=c++11

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage -std=c++11
LIBS += -lgcov
