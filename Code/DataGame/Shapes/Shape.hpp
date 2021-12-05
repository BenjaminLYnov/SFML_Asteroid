#ifndef SHAPE_H
#define SHAPE_H
#pragma once

#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Shape
{
public:
	Shape();
	~Shape();
	
	void Draw(sf::RenderWindow &window) const;

	sf::ConvexShape &GetShape();
	void SetCentralOrigin();
	void SetScale(float x, float y);

protected:
	sf::ConvexShape shape;
};
#endif