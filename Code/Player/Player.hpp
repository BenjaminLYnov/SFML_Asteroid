#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include "./MovePlayer.hpp"
#include "./Skills/Skills.hpp"
#include "../Timer/Timer.hpp"
#include "../Shapes/StartBattleShonenShipOverdrive.hpp"  

class Player
{
private:

	StartBattleShonenShipOverdrive ship;
	MovePlayer move;
	Skills skills;

public:
	Player();
	~Player();

	void Update();
	void input(Event &event);
	void draw(RenderWindow &window);
};
#endif