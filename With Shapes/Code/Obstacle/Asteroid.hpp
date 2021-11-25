#ifndef ASTEROID_H
#define ASTEROID_H

#include <chrono>
#include "../Math/Vector2D.hpp"
#include "../SFML/SfmlAudio.hpp"
#include "../Shapes/AsteroidShape.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Asteroid
{
private:

    BattleAsteroid asteroid;

public:

    Asteroid();
	~Asteroid();

    float speedMove;

	void asteroidMove();
	void Update();
	void draw(RenderWindow &window) const;
};


#endif
