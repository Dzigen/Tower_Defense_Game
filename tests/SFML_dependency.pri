ROOT = $${PWD}/../external

LIBS+= -L"$${ROOT}/SFML/lib" -lsfml-system -lsfml-window -lsfml-graphics
INCLUDEPATH += "$${ROOT}/SFML/include"
DEPENDPATH += "$${ROOT}/SFML/include"
