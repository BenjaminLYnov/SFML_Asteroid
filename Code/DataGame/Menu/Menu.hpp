#ifndef MENU_H
#define MENU_H
#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Timer/Timer.hpp"

class Menu
{
public:
	Menu();
	~Menu();

	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window) const;
	
	bool GameStarted();
	bool GetIsPause();

private:
	sf::Font font;

	sf::Text titleText;
	sf::Text pressToPlayText;
	sf::Text gameControlsText;
	sf::Text pauseText;
	sf::Text pauseControlsText;
	sf::Text continueText;
	sf::Text quitText;
	sf::Text topScoreText;

	Timer pressToPlayTimer;
	float pressToPlayBlinkerDelais;

	bool isPause;
	bool isMenu;
	bool keyUp;
	bool keyEnter;
	int select;

	// Blink press to play text
	void PressToPlayBlinker();

	void SetTopScoreText();

	// Input Management

	void Input(sf::RenderWindow &window);
	void SelectingMenu();
	void InputSelecting();
	void InputStartGame();
	void InputPause(sf::RenderWindow &window);
};
#endif