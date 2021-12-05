#ifndef SKILLS_H
#define SKILLS_H
#pragma once

#include <vector>
#include "./Laser.hpp"
#include "Teleportation.hpp"

class Skills
{
public:
	Skills();
	~Skills();

	float lifeExpectancyLaser;
	std::vector<Laser> &GetLasers();
	Laser &GetLastLasers();
	
	void Update();
	void Draw(sf::RenderWindow &window) const;

	int GetLasersQuantity();
	void DestroyLaser();
	void InputLaser(sf::Vector2f target, float rotation, float speedMove);
	void InputTeleportation(sf::ConvexShape &shape);

private:
	std::vector<Laser> lasers;
	Teleportation teleportation;
	bool keyJ;
	bool keyK;
	SfmlAudio *laserSound;
};
#endif
