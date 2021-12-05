#include "LaserShape.hpp"

LaserShape::LaserShape()
{
    shape.setPointCount(4);

    shape.setPoint(0, sf::Vector2f(0.f, 50.f));
    shape.setPoint(1, sf::Vector2f(20.f, 50.f));
    shape.setPoint(2, sf::Vector2f(20.f, 55.f));
    shape.setPoint(3, sf::Vector2f(0.f, 55.f));

    shape.setFillColor(sf::Color(10, 238, 223));

    SetCentralOrigin();
}

LaserShape::~LaserShape()
{
}



