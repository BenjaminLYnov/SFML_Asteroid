#ifndef LASER_H
#define LASER_H
#pragma once

#include "../../SFML/SfmlAudio.hpp"
#include "../../Shapes/LaserShape.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

#define PI 3.14159265

class Laser
{
private:
	bool sent;
    bool keySpace;
	double laserPosX;
	Vector2f dir;

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
