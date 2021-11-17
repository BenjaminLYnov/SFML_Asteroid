#include "Vector2D.hpp"  
	
Vector2D::Vector2D()
{
	
}
	
Vector2D::~Vector2D()
{
	
}

float Vector2D::Distance(Vector2f vec1, Vector2f vec2) 
{
	return sqrt(pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2));
}

Vector2f Vector2D::Normalized(Vector2f vec) 
{
    Vector2f vecNormalized;
    float norme = sqrt(vec.x * vec.x + vec.y + vec.y);
    vecNormalized.x = vec.x / norme;
    vecNormalized.y = vec.y / norme;
	return vecNormalized;
}