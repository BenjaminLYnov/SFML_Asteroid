#ifndef TELEPORTATION_H
#define TELEPORTATION_H
#pragma once

#include <SFML/Graphics/ConvexShape.hpp>
#include "../../SfmlAudio/SfmlAudio.hpp"

class Teleportation
{
public:
	Teleportation();
	~Teleportation();

	void InstantTeleportation(sf::ConvexShape &shape);

private:
	SfmlAudio *teleportationSound;
};
#endif