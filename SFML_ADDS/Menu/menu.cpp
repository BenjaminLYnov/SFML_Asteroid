#include "menu.h"

Menu::Menu() {
    PrintMenu();
    draw();
}

Menu::~Menu() {}

void Menu::PrintMenu() {

    font.loadFromFile("C:/Qt/Projects/SFML_ADDS/ressources/font/Asteroid.ttf");

    text.setFont(font);
    text.setString("ASTEROID");
    text.setCharacterSize(128);
    text.setPosition(550, 100);
    text.setFillColor( sf::Color::Transparent);
    text.setStyle(sf::Text::Style::Bold);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(2);

    text2.setFont(font);
    text2.setString("PRESS SPACE TO PLAY");
    text2.setCharacterSize(32);
    text2.setPosition(750, 650);
}

void Menu::PrintScore() {

    sf::RenderWindow window (sf::VideoMode(700,850), "SCORES");
    std::string line;
    std::ifstream myfile;

    // Accede aux scores depuis un fichier txt externe

    myfile.open ("C:/Qt/Projects/SFML_ADDS/PlayerScore/AllScore.txt");

    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            getScore += line;
            getScore += '\n';
        }
        myfile.close();
    }
    text.setString(getScore);
    text.setFont(font);
    text.setCharacterSize(48    );
    text.setPosition(20, 30);

    while (window.isOpen()) {
        while ( window.pollEvent(show)) {
            if(show.key.code == sf::Keyboard::Enter) {
                window.close();
                getScore.clear();
                PrintMenu();
            }
        }
        window.clear();
        window.draw(text);
        window.display();
    }
}

void Menu::draw() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.key.code == sf::Keyboard::Space) {
                window.close();
            //  Appele la fonction qui print le jeu
            }
            else if (event.key.code == sf::Keyboard::Escape) {
                PrintScore();
            }
        }

        window.clear();
        window.draw(text);
        window.draw(text2);
        window.display();
    }
}
