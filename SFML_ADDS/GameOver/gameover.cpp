#include "gameover.h"

GameOver::GameOver()
{
    GameOverWindows();
}

GameOver::~GameOver() {}

void GameOver::GameOverWindows() {

    sf::RenderWindow window (sf::VideoMode(300,300), "Game Over");
//    Buffer1.loadFromFile("mainTheme.ogg");


    while ( window.isOpen( ) ) {
        while ( window.pollEvent(typing)) {
            if(typing.key.code == sf::Keyboard::Enter) {
                SaveScore();
                window.close();
            }
            if (typing.key.code == sf::Keyboard::BackSpace) {
                output.clear();
            }
            else if (typing.type == sf::Event::TextEntered) {
                WritePsuedo();
            }
        }

        window.clear();
        window.draw(input);
        window.display();
    }
}

// Le joueur rentre son nom au moment du game over

void GameOver::WritePsuedo() {

    fontScore.loadFromFile("C:/Qt/Projects/SFML_ADDS/ressources/font/Asteroid.ttf");

    if (typing.text.unicode < 128) {
        output += static_cast<char>(typing.text.unicode);
        input.setString(output);
        input.setFont(fontScore);
        input.setCharacterSize(24);
        input.setPosition(20, 20);
    }
}


// Enregistre le score du joueur dans un fichier au moment du game over

void GameOver::SaveScore() {
    std::string const inventaire("C:/Qt/Projects/SFML_ADDS/PlayerScore/AllScore.txt");
    std::ofstream data(inventaire.c_str(), std::ofstream::out | std::ofstream::app);
    if (data) {
        data << output << "\t" << PlayerScore::finalScore << std::endl;
    } else {
        std::cout << "ERROR: File cannot be open" << std::endl;
    }
}
