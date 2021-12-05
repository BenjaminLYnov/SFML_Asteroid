#ifndef INVULNERABLE_H
#define INVULNERABLE_H
#pragma once

#include "../Timer/Timer.hpp"
#include <SFML/Graphics/ConvexShape.hpp>

class Invulnerable
{
public:
	Invulnerable();
	~Invulnerable();

	float invulnerableDelay;
	float blinkerDelay;
	bool isInvulnerable;

	void InvulnerableBlinker(sf::ConvexShape &shape);
	void BecomeInvulnerable();

private:
	Timer invulnerableTimer;
	Timer blinkerTimer;
	void Invisible(sf::ConvexShape &shape);
	void Visible(sf::ConvexShape &shape);
};
#endif