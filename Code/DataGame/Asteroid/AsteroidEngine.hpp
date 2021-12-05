#ifndef ASTEROIDENGINE_H
#define ASTEROIDENGINE_H
#pragma once

#include "./Asteroid.hpp"
#include <vector>

class AsteroidEngine
{
public:
	AsteroidEngine();
	~AsteroidEngine();

	void Update();
	void Draw(sf::RenderWindow &window) const;

	std::vector<Asteroid> &GetAsteroids();
	Asteroid &GetAsteroid(int indice);
	Asteroid &GetLastAsteroid();

	void CreateAsteroid();
	void CreateAsteroid(char size);
	void DestroyAsteroid(int indice);

private:
	std::vector<Asteroid> asteroids;
};
#endif