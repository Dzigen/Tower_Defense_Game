ROOT = $${PWD}/../external/SFML

CONFIG(debug, debug|release){
LIBS += -L$${ROOT}/lib/debug/
LIBS += -lsfml-system-d -lsfml-window-d -lsfml-graphics-d -lsfml-network-d -lsfml-audio-d
}

CONFIG(release, debug|release){
LIBS += -L$${ROOT}/lib/release/
LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
}

INCLUDEPATH +=$${ROOT}/include \
              $${ROOT}/..

DEPENDPATH +=$${ROOT}/include
