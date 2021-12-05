#ifndef OVNI_H
#define OVNI_H
#pragma once

#include "../Shapes/OVNIShape.hpp"

class OVNI
{
public:
	OVNI();
	~OVNI();

	void Draw(sf::RenderWindow &window) const;
	void MoveOnTarget(sf::Vector2f target);
	sf::ConvexShape &GetShape();

private:
	OVNIShape ovniShape;
	sf::Vector2f direction;
	float speedMove;

};
#endif