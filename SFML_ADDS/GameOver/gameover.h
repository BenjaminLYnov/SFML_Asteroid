#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "PlayerScore/playerscore.h"

class GameOver
{
public:
    GameOver();
    ~GameOver();
    void WritePsuedo();
    void SaveScore();
    void GameOverWindows();
protected:
    std::string playerPsuedo;
    sf::Text input;
    std::string output;
    sf::Font fontScore;
    sf::Event typing;
};

#endif // GAMEOVER_H
