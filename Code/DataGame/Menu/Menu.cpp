#include "Menu.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "../ScoreManager/ScoreManager.hpp"
#include <string>

Menu::Menu()
{
    font.loadFromFile("ressources/font/Asteroid.ttf");

    titleText.setFont(font);
    pressToPlayText.setFont(font);
    gameControlsText.setFont(font);
    pauseControlsText.setFont(font);
    pauseText.setFont(font);
    continueText.setFont(font);
    quitText.setFont(font);
    topScoreText.setFont(font);

    titleText.setCharacterSize(128);
    pressToPlayText.setCharacterSize(32);
    gameControlsText.setCharacterSize(32);
    pauseControlsText.setCharacterSize(32);
    pauseText.setCharacterSize(128);
    continueText.setCharacterSize(32);
    quitText.setCharacterSize(32);
    topScoreText.setCharacterSize(32);

    titleText.setPosition(500, 100);
    pressToPlayText.setPosition(750, 650);
    gameControlsText.setPosition(50, 700);
    pauseControlsText.setPosition(1200, 600);
    pauseText.setPosition(750, 100);
    continueText.setPosition(850, 500);
    quitText.setPosition(850, 700);
    topScoreText.setPosition(50, 10);

    titleText.setFillColor(sf::Color::Transparent);
    titleText.setStyle(sf::Text::Style::Bold);
    titleText.setOutlineColor(sf::Color::White);
    titleText.setOutlineThickness(2);

    titleText.setString("ASTEROID 79");
    pressToPlayText.setString("PRESS Enter TO PLAY");
    gameControlsText.setString("Game Controls :\n\nMove Forward -> S\nRotation Left -> Q\nRotation Right -> D\nFire -> J\nTeleportation -> K\nPause Game -> Enter");
    pauseControlsText.setString("Pause Controls :\n\nChange selecting -> Z / S / Up / Down\nConfirm -> Enter");
    pauseText.setString("Pause");
    continueText.setString("Continue");
    quitText.setString("Close Game");
    SetTopScoreText();

    pressToPlayBlinkerDelais = 0.7f;
    select = 1;
    keyUp = true;
    keyEnter = true;
    isMenu = true;
    isPause = false;
}

Menu::~Menu() {}

void Menu::Update(sf::RenderWindow &window)
{
    Input(window);
    SelectingMenu();
    PressToPlayBlinker();
}

void Menu::Draw(sf::RenderWindow &window) const
{
    if (isMenu)
    {
        window.draw(titleText);
        window.draw(pressToPlayText);
        window.draw(gameControlsText);
        window.draw(topScoreText);
    }

    if (isPause)
    {
        window.draw(pauseText);
        window.draw(continueText);
        window.draw(quitText);
        window.draw(gameControlsText);
        window.draw(pauseControlsText);
        window.draw(topScoreText);
    }
}

bool Menu::GameStarted()
{
    if (isMenu)
        return false;
    else
        return true;
}

bool Menu::GetIsPause()
{
    return isPause;
}

void Menu::PressToPlayBlinker()
{
    if (isMenu)
    {
        pressToPlayTimer.UpTime();

        if (pressToPlayTimer.GetTime() > pressToPlayBlinkerDelais)
            pressToPlayText.setFillColor(sf::Color(250, 250, 250, 0)); // Show press to play text
        else
            pressToPlayText.setFillColor(sf::Color(250, 250, 250, 250)); // Dont show press to play text

        if (pressToPlayTimer.GetTime() > pressToPlayBlinkerDelais * 2)
            pressToPlayTimer.Reset();
    }
}

void Menu::Input(sf::RenderWindow &window)
{
    if (isMenu)
        InputStartGame();

    InputPause(window);

    if (isPause)
        InputSelecting();
}

void Menu::InputStartGame()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && keyEnter)
    {
        isMenu = false;
        keyEnter = false;
    }
}

void Menu::InputPause(sf::RenderWindow &window)
{
    if (!isMenu)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && keyEnter)
        {
            if (!isPause)
                isPause = true;

            else
            {
                if (select == 1)
                    isPause = false;

                if (select == 2)
                    window.close();
            }
            keyEnter = false;
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            keyEnter = true;
}

void Menu::InputSelecting()
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) &&
        keyUp)
    {
        keyUp = false;
        if (select == 1)
            select = 2;
        else
            select = 1;
    }

    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
    {
        keyUp = true;
    }
}

void Menu::SelectingMenu()
{
    if (select == 1)
    {
        quitText.setFillColor(sf::Color::White);
        continueText.setFillColor(sf::Color::Red);
    }
    else if (select == 2)
    {
        continueText.setFillColor(sf::Color::White);
        quitText.setFillColor(sf::Color::Red);
    }
}

void Menu::SetTopScoreText()
{
    std::string topScore = "Top Score :\n\n";
    for (int i = 0; i < ScoreManager::GetTopScore(10).size(); i++)
        topScore += ScoreManager::GetTopPseudo(10)[i] + " : " + std::to_string(ScoreManager::GetTopScore(10)[i]) + "\n";
    topScoreText.setString(topScore);
}
