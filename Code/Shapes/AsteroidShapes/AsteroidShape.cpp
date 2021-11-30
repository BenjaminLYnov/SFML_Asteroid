#include "Asteroidshape.hpp"

AsteroidShape::AsteroidShape()
{
    type = RandomNumber::RandomInt(1, 3);

    float posX, posY;
    
    if (RandomNumber::RandomInt(0, 1) == 0)
        posX = RandomNumber::RandomInt(-100, 0);
    else
        posX = RandomNumber::RandomInt(1920, 2000);

    if (RandomNumber::RandomInt(0, 1) == 0)
        posY = RandomNumber::RandomInt(-100, 0);
    else
        posY = RandomNumber::RandomInt(1080, 1200);

    shape.setPosition(Vector2f(posX, posY));

    shape.setFillColor(Color(123, 125, 125));
}

AsteroidShape::~AsteroidShape()
{
}

// ConvexShape AsteroidShape::getShape() const
// {
//     return shape;
// }

void AsteroidShape::draw(RenderWindow &window) const
{
    window.draw(shape);
}
