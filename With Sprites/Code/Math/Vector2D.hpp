#ifndef VECTOR2D_H
#define VECTOR2D_H
#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Vector2D
{
private:
public:
	Vector2D();
	~Vector2D();

	static float Distance(Vector2f vec1, Vector2f vec2);
	static Vector2f Normalized(Vector2f vec);
};
#endif