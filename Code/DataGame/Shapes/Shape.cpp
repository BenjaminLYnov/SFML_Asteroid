#include "Shape.hpp"
#include "../Math/Vector2D.hpp"

Shape::Shape()
{
}

Shape::~Shape()
{
}

void Shape::Draw(sf::RenderWindow &window) const
{
    window.draw(shape);
}

sf::ConvexShape &Shape::GetShape()
{
    return shape;
}

void Shape::SetCentralOrigin()
{
    sf::Vector2f less, most;
    for (int i = 0; i < shape.getPointCount(); i++)
    {
        if (i == 0)
        {
            less = shape.getPoint(i);
            most = shape.getPoint(i);
        }

        if (shape.getPoint(i).x < less.x)
            less.x = shape.getPoint(i).x;
        if (shape.getPoint(i).x > most.x)
            most.x = shape.getPoint(i).x;

        if (shape.getPoint(i).y < less.y)
            less.y = shape.getPoint(i).y;
        if (shape.getPoint(i).y > most.y)
            most.y = shape.getPoint(i).y;
    }
    shape.setOrigin((most.x + less.x) / 2, (most.y + less.y) / 2);
}

void Shape::SetScale(float x, float y)
{
    shape.setScale(x, y);
}
