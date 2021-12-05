#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu();
    ~Menu();
    void PrintMenu();
    void PrintScore();
    void draw();
protected:
    sf::Text text;
    sf::Text text2;
    sf::Font font;
    std::string getScore;
    sf::Event show;
};

#endif // MENU_H
