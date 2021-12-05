#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include "./MovePlayer.hpp"
#include "./Skills/Skills.hpp"
#include "../Shapes/BattleShip.hpp"
#include "./Invulnerable.hpp"

class Player
{
public:
	Player();
	~Player();

	void Update();
	void Draw(sf::RenderWindow &window) const;

	sf::ConvexShape &GetShape();
	Skills &GetSkills();
	int &GetHp();
	void Input();
	void GetHurt();

private:
	int hp;
	BattleShip ship;
	MovePlayer move;
	Skills *skills;
	Invulnerable invulnerable;
	SfmlAudio *hurtSound;
};
#endif