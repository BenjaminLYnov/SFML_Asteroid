#ifndef MOVEPLAYER_H
#define MOVEPLAYER_H
#pragma once

#include <iostream>
#include "../Timer/Timer.hpp"
#include "../SFML/SfmlImage.hpp"
#include "../SFML/SfmlAudio.hpp"


using namespace sf;

class MovePlayer
{
private:
	bool moveUp;
	bool moveDown;
	bool moveLeft;
	bool moveRight;

	bool rotationLeft;
	bool rotationRight;

public:
	MovePlayer();
	MovePlayer(double SpeedMove);
	~MovePlayer();

	double speedMove;
	double speedRotation;

	void inputMove(Event &event);
	void inputRotation(Event &event);
	
	void moveSprite(Sprite &sprite);
	void rotationSprite(Sprite &sprite);
};
#endif