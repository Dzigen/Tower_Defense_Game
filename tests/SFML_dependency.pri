ROOT = $${PWD}/../external

LIBS        += -L"$${ROOT}/SFML/lib/debug/" -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "$${ROOT}/SFML/include"
DEPENDPATH += "$${ROOT}/SFML/include"
