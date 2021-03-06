ROOT = $${PWD}/../external/SFML

CONFIG(release, debug|release){
LIBS += -L"$${ROOT}/lib/release/"
LIBS += -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio
}
CONFIG(debug, debug|release){
LIBS += -L"$${ROOT}/lib/debug/"
LIBS += -lsfml-system-d -lsfml-window-d -lsfml-graphics-d -lsfml-network-d -lsfml-audio-d
}

INCLUDEPATH +=$${ROOT}/include \
              $${ROOT}/..

DEPENDPATH +=$${ROOT}/include
