include(SFML_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG+=c++11

SOURCES += \
    base_hero_explosion.cpp \
    effect_of_the_rune.cpp \
    end_game.cpp \
    enemy_hit.cpp \
    game_draw.cpp \
    game_end_window.cpp \
    game_process.cpp \
    hero_shot.cpp \
    main.cpp \
    mouse_click.cpp \
    move_enemy.cpp \
    move_hero.cpp \
    pause_menu.cpp \
    randomize_enemy_coordinates.cpp \
    randomize_enemy_target_coordinates.cpp \
    randomize_enemy_type.cpp \
    randomize_rune_coordinates.cpp \
    take_rune.cpp \
    update_spawn_rune.cpp


HEADERS += \
    cursors.h \
    game_end_window.h \
    game_objects.h \
    game_process.h \
    main.h \
    menu_bar.h \
    move_enemy.h \
    pause_end_menu.h \
    take_rune.h \
    tool_bar.h \
    update_spawn_rune.h

QMAKE_CFLAGS +=  -Wall -Wextra -Werror
QMAKE_CXXFLAGS +=-std=c++11

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
