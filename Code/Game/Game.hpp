#ifndef GAME_H
#define GAME_H
#pragma once

#include "GameEngine.hpp"
#include "GameOverEngine.hpp"

#define WIDTH 1920
#define HEIGHT 1080

class Game
{
public:
	Game();
	~Game();

	void Run();

private:
	sf::RenderWindow *window;
	GameEngine *gameEngine;
	GameOverEngine *gameOverEngine;

	Timer ClosingGameTimer;
	void CloseGame();
};
#endif