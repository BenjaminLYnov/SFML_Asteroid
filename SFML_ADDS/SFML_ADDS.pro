TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#WINDOWS
# put SFML file in the same location as project
LIBS += -L"..\SFML-2.5.1\lib"
LIBS += -L"..\SFML-2.5.1\bin"

#MAC
#LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\SFML-2.5.1\include"
DEPENDPATH += "..\SFML-2.5.1\include"

SOURCES += \
        GameOver/gameover.cpp \
        Menu/menu.cpp \
        PlayerScore/playerscore.cpp \
        main.cpp

HEADERS += \
    GameOver/gameover.h \
    Menu/menu.h \
    PlayerScore/playerscore.h
