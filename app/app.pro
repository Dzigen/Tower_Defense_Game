include(SFML_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        game_draw.cpp \
        game_process.cpp \
        main.cpp \
        move_hero.cpp \
        pause_menu.cpp

HEADERS += \
    cursors.h \
    game_objects.h \
    game_process.h \
    main.h \
    menu_bar.h \
    pause_menu.h \
    tool_bar.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
