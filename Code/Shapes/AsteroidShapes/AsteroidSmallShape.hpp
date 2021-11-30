#ifndef ASTEROIDSMALLSHAPE_H
#define ASTEROIDSMALLSHAPE_H
#pragma once
#include "AsteroidShape.hpp"  

class AsteroidSmallShape : public AsteroidShape
{
private:
public:
	AsteroidSmallShape();
	~AsteroidSmallShape();


	void type1();
	void type2();
	void type3();
};
#endif