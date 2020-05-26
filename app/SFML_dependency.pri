ROOT = $${PWD}/../external/SFML

CONFIG(release, debug|release){
LIBS        += -L"$${ROOT}/SFML/lib/release/"
LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
}
CONFIG(debug, debug|release){
LIBS += -L"$${ROOT}/SFML/lib/debug/"
LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
}

INCLUDEPATH += "$${ROOT}/SFML/include"
DEPENDPATH += "$${ROOT}/SFML/include"
