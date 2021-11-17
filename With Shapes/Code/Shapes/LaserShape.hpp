#ifndef LASERSHAPE_H
#define LASERSHAPE_H
#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class LaserShape
{
private:
public:
	LaserShape();
	~LaserShape();

	ConvexShape shape;
};
#endif