ROOT = $${PWD}/../external
LIBS        += -L"$${ROOT}/SFML/lib/debug/"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "$${ROOT}/SFML/include"
DEPENDPATH += "$${ROOT}/SFML/include"
