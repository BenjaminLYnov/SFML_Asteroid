#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#pragma once

#include <Sfml/Graphics/Texture.hpp>
#include "Shape.hpp"

class BattleShip : public Shape
{
public:
	BattleShip();
	~BattleShip();

	sf::Texture texture;
};
#endif