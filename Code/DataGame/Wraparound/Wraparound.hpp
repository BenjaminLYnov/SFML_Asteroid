#ifndef WRAPAROUND_H
#define WRAPAROUND_H
#pragma once

#include <SFML/Graphics/ConvexShape.hpp>

class Wraparound
{
public:
	Wraparound();
	~Wraparound();

	static void MirorSide(sf::ConvexShape &shape);
};
#endif