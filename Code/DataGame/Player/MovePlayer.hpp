#ifndef MOVEPLAYER_H
#define MOVEPLAYER_H
#pragma once

#include "../SfmlAudio/SfmlAudio.hpp"
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/System/Vector2.hpp>
#include "../Math/Vector2D.hpp"

class MovePlayer
{
public:
	MovePlayer();
	MovePlayer(float SpeedMove);
	~MovePlayer();

	float speedMove;
	float speedRotation;

	void InputMove();
	void InputRotation();

	void MoveShape(sf::ConvexShape &shape);
	void RotationShape(sf::ConvexShape &shape);

private:
	bool moveForward;
	bool rotationLeft;
	bool rotationRight;

	sf::Vector2f direction;
};
#endif