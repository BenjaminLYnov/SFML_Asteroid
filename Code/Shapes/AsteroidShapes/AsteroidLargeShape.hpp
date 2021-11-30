#ifndef ASTEROIDLARGESHAPE_H
#define ASTEROIDLARGESHAPE_H
#pragma once
#include "AsteroidShape.hpp"

class AsteroidLargeShape : public AsteroidShape
{
private:
public:
	AsteroidLargeShape();
	~AsteroidLargeShape();

	void type1();
	void type2();
	void type3();
};
#endif