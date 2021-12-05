#include "UHD.hpp"
#include "../ScoreManager/ScoreManager.hpp"
#include <iostream>

UHD::UHD()
{
    level = 0;
    score = 0;

    font.loadFromFile("ressources/font/Asteroid.ttf");

    scoreText.setFont(font);
    hightestScoreText.setFont(font);

    scoreText.setCharacterSize(30);
    hightestScoreText.setCharacterSize(30);

    scoreText.setPosition(700, 30);
    hightestScoreText.setPosition(700, 60);

    hightestScore = ScoreManager::GetHightestScore();

    hightestScoreText.setString("Hightest Score : " + std::to_string(hightestScore));
}

UHD::~UHD()
{
}

void UHD::Draw(sf::RenderWindow &window, int numberShip) const
{
    window.draw(scoreText);
    window.draw(hightestScoreText);

    for (int i = 0; i < numberShip; i++)
        ship[i].Draw(window);
}

void UHD::Update(int numberShip)
{
    if (score > hightestScore)
        scoreText.setFillColor(sf::Color::Red);
    scoreText.setString("Current Score : " + std::to_string(score));
    SetPositionShip(numberShip);
}

int &UHD::GetScore()
{
    return score;
}

void UHD::UpScore(int number)
{
    score += number;
}

void UHD::UpLevel()
{
    level++;
}

void UHD::SetPositionShip(int numberShip)
{
    for (int i = 0; i < numberShip; i++)
        ship[i].GetShape().setPosition(1600 + i * 50, 50);
}
