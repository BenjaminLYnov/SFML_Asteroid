#ifndef ASTEROID_H
#define ASTEROID_H
#pragma once

#include "./AsteroidType/AsteroidSmall.hpp"
#include "./AsteroidType/AsteroidMedium.hpp"
#include "./AsteroidType/AsteroidLarge.hpp"

class Asteroid
{
private:
public:
	Asteroid();
	~Asteroid();

	vector<AsteroidLarge> asteroidsLarge;
	vector<AsteroidMedium> asteroidsMedium;
	vector<AsteroidSmall> asteroidsSmall;

	int deadTime;

	// // // // // // // // // // // // 
	// Create new asteroid

	// Chronometre

	Timer createNextAsteroidSmallTime;
	Timer createNextAsteroidMediumTime;
	Timer createNextAsteroidLargeTime;

	// Timeout
	float createNextAsteroidSmall;
	float createNextAsteroidMedium;
	float createNextAsteroidLarge;
	// // // // // // // // // // // // 

	// void GetHurt();
	void DestroyAsteroid();
	void CreateAsteroid();
	void Update();
	void Draw(RenderWindow &window) const;
};
#endif