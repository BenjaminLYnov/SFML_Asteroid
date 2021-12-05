#ifndef ASTEROID_H
#define ASTEROID_H
#pragma once

#include "../Timer/Timer.hpp"
#include "../Shapes/AsteroidShape.hpp"
#include "../SfmlAudio/SfmlAudio.hpp"

class Asteroid
{
public:
	Asteroid();
	Asteroid(int size);
	~Asteroid();

	void Update();
	void Draw(sf::RenderWindow &window) const;
	
	sf::ConvexShape &GetShape();
	int &GetSize();
	void PlayBangSound();


private:
	AsteroidShape asteroidShape;
	float speedMove;
	int size;
	sf::Vector2f direction;
	SfmlAudio *bangAsteorid;

	void Move();
	void SetSize(int size);
	void SetBangSound(int size);
};
#endif