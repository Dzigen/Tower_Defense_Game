ROOT = $${PWD}/../external

LIBS+= -L"$${ROOT}/SFML/lib/"  -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "$${ROOT}/SFML/include"
DEPENDPATH += "$${ROOT}/SFML/include"
