#ifndef COLLISION_H
#define COLLISION_H
#pragma once

#include <SFML/Graphics/ConvexShape.hpp>

class Collision
{
public:

	// Return true is 2 shapes are overlapped
	static bool IsTrigger(sf::ConvexShape &shape1, sf::ConvexShape &shape2);

	// Return ray's shape
	static float Ray(sf::ConvexShape &shape);
};
#endif