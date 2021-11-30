#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H
#pragma once

#include <iostream>
#include <chrono>
using namespace std;

#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>


class RandomNumber
{
private:
public:
	RandomNumber();
	~RandomNumber();


	static int RandomInt(int min, int max);
	static float RandomFloat(float min, float max);

};
#endif