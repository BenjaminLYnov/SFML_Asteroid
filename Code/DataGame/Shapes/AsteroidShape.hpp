#ifndef ASTEROIDSHAPE_H
#define ASTEROIDSHAPE_H
#pragma once

#include "./Shape.hpp"

class AsteroidShape : public Shape
{
public:
	AsteroidShape();
	~AsteroidShape();

private:
	int modele;

	void SetAsteroidOutsideScreen();
	void LoadModele();
	void Modele1();
	void Modele2();
	void Modele3();
};
#endif