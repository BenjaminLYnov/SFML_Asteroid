#ifndef WALL_H
#define WALL_H
#pragma once

#include "Collision.h"
#include "../Angle/Radius.hpp"
#include "../Include/MainInclude.hpp"

using namespace std;

class Wall
{
private:
public:
	Wall();
	~Wall();
	void isWall(Sprite &sprite1, Sprite &sprite2);
	void setNewPosition(Sprite &sprite1, Sprite &sprite2);
	double radius;
	double cornerRadius;
	double bilateralRadius;
	double cornerRadiusUpLeft;
	double cornerRadiusUpRight;
	double cornerRadiusDownLeft;
	double cornerRadiusDownRight;
};
#endif