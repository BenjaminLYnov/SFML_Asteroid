#ifndef RADIUS_H
#define RADIUS_H
#pragma once
#include "../Include/MainInclude.hpp"

#define PI 3.14159265

class Radius
{
private:
public:
	Radius();
	~Radius();
	static double distanceBeetween2Sprites(Sprite &sprite1, Sprite &sprite2);
	static double radiusBeetween2Sprites(Sprite &sprite1, Sprite &sprite2);
	static double radiusBeetween2Vector(double vec1X, double vec1Y, double vec2X, double vec2Y);
	static double radiusCorner(Sprite &sprite);
	static Sprite *mostNear(Sprite &spriteOrigin, Sprite &sprite1, Sprite &sprite2);
};
#endif