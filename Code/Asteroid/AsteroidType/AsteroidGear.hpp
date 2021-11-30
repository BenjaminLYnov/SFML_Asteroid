#ifndef ASTEROIDGEAR_H
#define ASTEROIDGEAR_H
#pragma once

#include <SFML/Graphics.hpp>
#include "../../Math/Vector2D.hpp"
#include "../../Timer/Timer.hpp"
#include "../../Math/RandomNumber.hpp"
#include "../../Shapes/AsteroidShapes/AsteroidShape.hpp"

using namespace sf;

class AsteroidGear
{
private:
public:
	AsteroidGear();
	~AsteroidGear();

	void Move();
	void Update();
	void Draw(RenderWindow &window) const;
	Timer lifeTime;

protected:
	AsteroidShape asteroidShape;
	int hp;
	float speedMove;
	Vector2f direction;
};
#endif