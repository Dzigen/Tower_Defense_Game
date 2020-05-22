ROOT = $${PWD}/../external
LIBS        += -L"$${ROOT}/SFML/lib/debug/"

CONFIG(debug, debug|release): LIBS += -lsfml-graphics-d -lsfml-window-d -lsfml-system-d
CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-system

INCLUDEPATH += "$${ROOT}/SFML/include"
DEPENDPATH += "$${ROOT}/SFML/include"
