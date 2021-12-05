#ifndef UHD_H
#define UHD_H
#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Shapes/BattleShip.hpp"

class UHD
{
public:
	UHD();
	~UHD();

	void Update(int numberShip);
	void Draw(sf::RenderWindow &window, int numberShip) const;
	
	int &GetScore();
	void UpScore(int number);
	void UpLevel();

private:
	int score;
	int level;
	int hightestScore;

	sf::Font font;
	sf::Text levelText;
	sf::Text scoreText;
	sf::Text hightestScoreText;
	BattleShip ship[3];

	void SetPositionShip(int numberShip);
};
#endif