#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include "./MovePlayer.hpp"
#include "../Timer/Timer.hpp"
#include "../SFML/SfmlImage.hpp"
#include "./Skills/Skills.hpp"


using namespace sf;

class Player
{
private:

	MovePlayer move;
	Skills skills;
	SfmlImage *vaisseauSprite;

public:
	Player();
	~Player();


	void Update();
	void draw(RenderWindow &window) const;
	void input(Event &event);

};
#endif