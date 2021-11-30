#ifndef ASTEROIDMEDIUMSHAPE_H
#define ASTEROIDMEDIUMSHAPE_H
#pragma once
#include "AsteroidShape.hpp"  

class AsteroidMediumShape : public AsteroidShape
{
private:
public:
	AsteroidMediumShape();
	~AsteroidMediumShape();

	void type1();
	void type2();
	void type3();
};
#endif