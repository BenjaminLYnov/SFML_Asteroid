#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu();
    ~Menu();
    void PrintMenu();
    void draw();
protected:
    sf::Text text;
    sf::Text text2;
    sf::Font font;
};

#endif // MENU_H
