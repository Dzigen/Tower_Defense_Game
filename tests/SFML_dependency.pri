ROOT = $${PWD}/../external

LIBS+= -L"$${ROOT}/SFML/lib/debug/" -lsfml-system-d -lsfml-window-d -lsfml-graphics-d -lsfml-network-d -lsfml-audio-d

INCLUDEPATH += "$${ROOT}/SFML/include"
DEPENDPATH += "$${ROOT}/SFML/include"
