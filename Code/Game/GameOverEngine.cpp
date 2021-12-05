#include "GameOverEngine.hpp"
#include "../DataGame/ScoreManager/ScoreManager.hpp"

GameOverEngine::GameOverEngine()
{
    isGameOver = false;
    isSaved = false;

    pseudoString = "";
    font.loadFromFile("ressources/font/Asteroid.ttf");

    gameOverText.setFont(font);
    pseudoText.setFont(font);
    scoreText.setFont(font);
    ThankYouForPlayingText.setFont(font);

    gameOverText.setString("Game Over");
    ThankYouForPlayingText.setString("Thank You For Playing !");

    gameOverText.setCharacterSize(128);
    ThankYouForPlayingText.setCharacterSize(128);

    gameOverText.setPosition(500, 200);
    scoreText.setPosition(500, 500);
    pseudoText.setPosition(500, 600);
    ThankYouForPlayingText.setPosition(150, 400);
}

GameOverEngine::~GameOverEngine() {}

void GameOverEngine::Draw(sf::RenderWindow &window)
{
    if (!isSaved)
    {
        window.draw(gameOverText);
        window.draw(scoreText);
        window.draw(pseudoText);
    }
    else
        window.draw(ThankYouForPlayingText);
}

void GameOverEngine::GameOver(bool isOver)
{
    isGameOver = isOver;
}

bool &GameOverEngine::GetIsOver()
{
    return isGameOver;
}

bool &GameOverEngine::GetIsSaved()
{
    return isSaved;
}

void GameOverEngine::WritePseudo(sf::Event event, int score)
{
    if (isGameOver)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !isSaved)
        {
            ScoreManager::SavePseudoAndScore(pseudoString, score);
            isSaved = true;
        }

        if (event.type == sf::Event::TextEntered)
            if (event.text.unicode < 128)
                if (static_cast<char>(event.text.unicode) != ':')
                    pseudoString += static_cast<char>(event.text.unicode);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
        {
            std::string string = "";
            if (pseudoString.size() > 1)
                for (int i = 0; i < pseudoString.size() - 1; i++)
                    string += pseudoString[i];
            pseudoString = string;
        }

        scoreText.setString("Your Score :\n\n" + std::to_string(score));
        pseudoText.setString("\nYour Pseudo (Press Enter To Confirm):\n\n" + pseudoString);
    }
}