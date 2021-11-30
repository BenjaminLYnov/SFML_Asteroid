#ifndef ASTEROIDSHAPE_H
#define ASTEROIDSHAPE_H
#pragma once

#include <SFML/Graphics.hpp>
#include "../../Math/RandomNumber.hpp"
using namespace sf;

class AsteroidShape
{
private:
public:
	AsteroidShape();
	~AsteroidShape();

	void draw(RenderWindow &window) const;
	ConvexShape shape;

protected:
	int type;
};
#endif