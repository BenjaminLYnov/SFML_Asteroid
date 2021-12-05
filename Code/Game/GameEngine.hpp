#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#pragma once

#include "../DataGame/DataGame.hpp"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window) const;
	
	int &GetScore();
	bool PlayerIsDead();

private:
	Player *player;
	AsteroidEngine *asteroidEngine;
	std::vector<OVNI> ovnis;
	UHD *uhd;
	Menu *menu;

	int asteroidNumber;

	void SetupLevel();
	void PlayerDammageOnAsteroid();
	void PlayerDammageOnOVNI();
	void AsteroidDammageOnPlayer();
	void OVNIDammageOnPlayer();
	void DammageStep();

	// OVNI Manager
	Timer createOVNICoolDown;
	SfmlAudio *ovniSound;
	bool playOnceOvniSound;

	void CreateOVNI();
	void ONVISound();
};
#endif