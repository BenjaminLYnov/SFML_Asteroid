#ifndef ASTEROID_H
#define ASTEROID_H
#pragma once

#include "../Math/Vector2D.hpp"
#include "../SFML/SfmlImage.hpp"
#include "../SFML/SfmlAudio.hpp"
#include <chrono>

using namespace sf;

class Asteroid
{
private:
	SfmlImage *mediumAsteroidImage;
	SfmlImage *smallAsteroidImage1;
	SfmlImage *smallAsteroidImage2;
	SfmlImage *verySmallAsteroidImage1[2];
	SfmlImage *verySmallAsteroidImage2[2];

public:
	Asteroid();
	~Asteroid();

	float speedMove;
	Vector2f mediumDir;
	Vector2f smallDir1;
	Vector2f smallDir2;

	void asteroidMove();
	void Update();
	void draw(RenderWindow &window) const;
};
#endif