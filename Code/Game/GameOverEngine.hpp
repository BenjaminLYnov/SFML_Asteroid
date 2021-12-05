#ifndef GAMEOVERENGINE_H
#define GAMEOVERENGINE_H
#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class GameOverEngine
{
public:
	GameOverEngine();
	~GameOverEngine();

	void Draw(sf::RenderWindow &window);
	
	bool &GetIsOver();
	bool &GetIsSaved();
	void GameOver(bool isOver);
	void WritePseudo(sf::Event event, int score);
	void SavePseudoAndScore(std::string pseudo, int score);

private:
	bool isGameOver;
	bool isSaved;

	sf::Text gameOverText;
	sf::Text pseudoText;
	sf::Text scoreText;
	sf::Text ThankYouForPlayingText;

	std::string pseudoString;
	sf::Font font;

};
#endif