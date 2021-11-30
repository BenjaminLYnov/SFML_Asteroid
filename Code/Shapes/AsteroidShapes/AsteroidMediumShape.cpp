#include "AsteroidMediumshape.hpp"

AsteroidMediumShape::AsteroidMediumShape()
{
    if (type == 1)
        type1();
    else if (type == 2)
        type2();
    else if (type == 3)
        type3();
}

AsteroidMediumShape::~AsteroidMediumShape()
{
}

void AsteroidMediumShape::type1()
{
    shape.setPointCount(6);
    shape.setPoint(0, Vector2f(-19.429f, -22.571f));
    shape.setPoint(1, Vector2f(5.143f, -45.714f));
    shape.setPoint(2, Vector2f(13.429f, -25.429f));
    shape.setPoint(3, Vector2f(10.857f, 7.714f));
    shape.setPoint(4, Vector2f(-15.143f, 9.143f));
    shape.setPoint(5, Vector2f(-23.429f, -6.000f));
}

void AsteroidMediumShape::type2()
{
    shape.setPointCount(4);
    shape.setPoint(0, Vector2f(-43.143f, -27.143f));
    shape.setPoint(1, Vector2f(-30.286f, 28.571f));
    shape.setPoint(2, Vector2f(18.857f, 18.000f));
    shape.setPoint(3, Vector2f(-0.571f, -19.143f));
}

void AsteroidMediumShape::type3()
{
    shape.setPointCount(4);
    shape.setPoint(0, Vector2f(-36.857f, -13.143f));
    shape.setPoint(1, Vector2f(36.286f, -44.857f));
    shape.setPoint(2, Vector2f(30.000f, 26.000f));
    shape.setPoint(3, Vector2f(-22.000f, 10.000f));
}
