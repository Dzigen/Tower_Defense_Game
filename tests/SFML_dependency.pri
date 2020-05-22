ROOT = $${PWD}/../external

LIBS        += -L"$${ROOT}/SFML/lib/debug/"  -lsfml-graphics-d  -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "$${ROOT}/SFML/include"
DEPENDPATH += "$${ROOT}/SFML/include"
