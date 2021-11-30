#include "AsteroidSmallshape.hpp"

AsteroidSmallShape::AsteroidSmallShape()
{
    if (type == 1)
        type1();
    else if (type == 2)
        type2();
    else if (type == 3)
        type3();
}

AsteroidSmallShape::~AsteroidSmallShape()
{
}

void AsteroidSmallShape::type1()
{
    shape.setPointCount(5);
    shape.setPoint(0, Vector2f(-10.857f, -10.286f));
    shape.setPoint(1, Vector2f(19.429f, -10.571f));
    shape.setPoint(2, Vector2f(23.714f, 2.000f));
    shape.setPoint(3, Vector2f(6.000f, 11.429f));
    shape.setPoint(4, Vector2f(-6.000f, 3.714f));
}

void AsteroidSmallShape::type2()
{
    shape.setPointCount(6);
    shape.setPoint(0, Vector2f(-11.143f, -8.000f));
    shape.setPoint(1, Vector2f(-0.571f, -6.857f));
    shape.setPoint(2, Vector2f(4.000f, 0.571f));
    shape.setPoint(3, Vector2f(3.143f, 6.286f));
    shape.setPoint(4, Vector2f(-5.714f, 3.714f));
    shape.setPoint(5, Vector2f(-10.000f, -2.571f));
}

void AsteroidSmallShape::type3()
{
    shape.setPointCount(4);
    shape.setPoint(0, Vector2f(-7.143f, -7.714f));
    shape.setPoint(1, Vector2f(5.143f, 0.857f));
    shape.setPoint(2, Vector2f(0.857f, 5.143f));
    shape.setPoint(3, Vector2f(-5.143f, -3.143f));
}
