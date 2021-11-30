#include "AsteroidLargeshape.hpp"

AsteroidLargeShape::AsteroidLargeShape()
{
    if (type == 1)
        type1();
    else if (type == 2)
        type2();
    else if (type == 3)
        type3();
}

AsteroidLargeShape::~AsteroidLargeShape()
{
}

void AsteroidLargeShape::type1()
{
    shape.setPointCount(5);
    shape.setPoint(0, Vector2f(-62.571f, -15.714f));
    shape.setPoint(1, Vector2f(-28.000f, -68.286f));
    shape.setPoint(2, Vector2f(41.143f, -48.571f));
    shape.setPoint(3, Vector2f(31.143f, 23.143f));
    shape.setPoint(4, Vector2f(-37.143f, 25.429f));
}

void AsteroidLargeShape::type2()
{
    shape.setPointCount(4);
    shape.setPoint(0, Vector2f(-60.857f, -31.714f));
    shape.setPoint(1, Vector2f(14.571f, -81.143f));
    shape.setPoint(2, Vector2f(8.857f, 48.000f));
    shape.setPoint(3, Vector2f(-45.143f, 61.429f));
}

void AsteroidLargeShape::type3()
{
    shape.setPointCount(4);
    shape.setPoint(0, Vector2f(-75.714f, -9.714f));
    shape.setPoint(1, Vector2f(77.714f, -75.714f));
    shape.setPoint(2, Vector2f(57.429f, 65.429f));
    shape.setPoint(3, Vector2f(-25.714f, 40.286f));
}
