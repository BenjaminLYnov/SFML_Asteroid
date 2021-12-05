#include "Collision.hpp"
#include "../Math/Vector2D.hpp"

bool Collision::IsTrigger(sf::ConvexShape &shape1, sf::ConvexShape &shape2)
{
	float ray1 = Ray(shape1);
	float ray2 = Ray(shape2);

	if (Vector2D::Distance(shape1.getPosition(), shape2.getPosition()) < (Ray(shape1) + Ray(shape2)))
		return true;
	else
		return false;
}

float Collision::Ray(sf::ConvexShape &shape)
{
	float diameter = 0;
	for (int i = 0; i < shape.getPointCount(); i++)
		for (int j = 0; j < shape.getPointCount(); j++)
			if (Vector2D::Distance(shape.getPoint(i), shape.getPoint(j)) * shape.getScale().x > diameter)
				diameter = Vector2D::Distance(shape.getPoint(i), shape.getPoint(j)) * shape.getScale().x;
	return diameter / 2.f;
}
