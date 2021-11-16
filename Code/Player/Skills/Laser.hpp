#ifndef LASER_H
#define LASER_H
#pragma once

#include "../../Include/MainInclude.hpp"

#define PI 3.14159265

class Laser
{
private:

	bool sent; 	
	bool keyJ;
	double laserPosX;
  	Vector2f dir;

public:
	Laser();
	~Laser();

	float speedMove;

	SfmlImage *laserImage;

	void inputSendLaser(Event &event, Vector2f target, float rotation);
	void laserMove();
	void Update();
	void draw(RenderWindow &window) const;
};
#endif