#ifndef LASER_H
#define LASER_H
#pragma once

#include "../../SFML/SfmlAudio.hpp"
#include "../../Shapes/LaserShape.hpp"
#include "../../Math/Vector2D.hpp"
#include <SFML/Window.hpp>



class Laser
{
private:
	bool sent;
    bool keySpace;
	double laserPosX;
	Vector2f direction;

public:
	Laser();
	~Laser();

	float speedMove;

	LaserShape laserShape;

	void inputSendLaser(Event &event, Vector2f target, float rotation);
	void laserMove();
	void Update();
	void draw(RenderWindow &window) const;
};
#endif
