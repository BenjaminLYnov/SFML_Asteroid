TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#WINDOWS
# put SFML file in the same location as project
LIBS += -L"..\SFML-2.5.1\lib" #change this
LIBS += -L"..\SFML-2.5.1\bin" #change this

#MAC
#LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\SFML-2.5.1\include" #change this
DEPENDPATH += "..\SFML-2.5.1\include" #change this


SOURCES += \
        ../main.cpp \
        Collision/Collision.cpp \
        Math/Vector2D.cpp \
        Obstacle/Asteroid.cpp \
        Player/MovePlayer.cpp \
        Player/Player.cpp \
        Player/Skills/Laser.cpp \
        Player/Skills/Skills.cpp \
        SFML/SfmlAudio.cpp \
        Shapes/AsteroidShape.cpp \
        Shapes/LaserShape.cpp \
        Shapes/StartBattleShonenShipOverdrive.cpp \
        Timer/Timer.cpp

HEADERS += \
    Collision/Collision.h \
    Math/Vector2D.hpp \
    Obstacle/Asteroid.hpp \
    Player/MovePlayer.hpp \
    Player/Player.hpp \
    Player/Skills/Laser.hpp \
    Player/Skills/Skills.hpp \
    SFML/SfmlAudio.hpp \
    Shapes/AsteroidShape.h \
    Shapes/LaserShape.hpp \
    Shapes/StartBattleShonenShipOverdrive.hpp \
    Timer/Timer.hpp

DISTFILES += \
    ../Game/Game.exe \
    ../Game/libgcc_s_seh-1.dll \
    ../Game/libstdc++-6.dll \
    ../Game/libwinpthread-1.dll \
    ../Game/openal32.dll \
    ../Game/ressources/font/TPHylian-WiiRegular.otf \
    ../Game/ressources/font/The Wild Breath of Zelda.otf
