#ifndef VECTOR2D_H
#define VECTOR2D_H
#pragma once

#include "../Include/MainInclude.hpp"
	
class Vector2D  
{
	private:

	public:

		Vector2D();
		~Vector2D();

		float Distance(Vector2f vec1, Vector2f vec2);
		Vector2f Normalized(Vector2f vec1, Vector2f vec2);

};
#endif