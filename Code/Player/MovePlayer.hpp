#ifndef MOVEPLAYER_H
#define MOVEPLAYER_H
#pragma once

#include <iostream>
#include "../SFML/SfmlAudio.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../Math/Vector2D.hpp"

class MovePlayer
{
private:
	bool moveForward;
	bool rotationLeft;
	bool rotationRight;

	Vector2f direction;


public:
	MovePlayer();
	MovePlayer(float SpeedMove);
	~MovePlayer();

	float speedMove;
	float speedRotation;

	void inputMove(Event &event);
	void inputRotation(Event &event);
	
	void moveSprite(ConvexShape &sprite);
	void rotationSprite(ConvexShape &sprite);
};
#endif