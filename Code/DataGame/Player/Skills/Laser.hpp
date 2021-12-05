#ifndef LASER_H
#define LASER_H
#pragma once

#include "../../Shapes/LaserShape.hpp"
#include "../../Math/Vector2D.hpp"
#include "../../Timer/Timer.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Laser
{
public:
	Laser();
	Laser(sf::Vector2f target, float rotation, float speedMove);
	~Laser();

	float speedMove;
	Timer lifeTime;

	void Update();
	void Draw(sf::RenderWindow &window) const;

	sf::ConvexShape &GetShape();

private:
	LaserShape laserShape;
	sf::Vector2f direction;
	void LaserMove();
};
#endif
