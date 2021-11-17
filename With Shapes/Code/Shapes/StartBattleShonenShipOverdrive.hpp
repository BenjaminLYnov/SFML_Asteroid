#ifndef STARTBATTLESHONENSHIPOVERDRIVE_H
#define STARTBATTLESHONENSHIPOVERDRIVE_H
#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class StartBattleShonenShipOverdrive
{
private:
public:
	StartBattleShonenShipOverdrive();
	~StartBattleShonenShipOverdrive();

	ConvexShape shape;
	ConvexShape getShape();
	void draw(RenderWindow &window) const;
};
#endif