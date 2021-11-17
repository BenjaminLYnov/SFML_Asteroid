#include "LaserShape.hpp"

LaserShape::LaserShape()
{

    shape.setPointCount(4);

    shape.setPoint(0, Vector2f(-60.f, -10.f));
    shape.setPoint(1, Vector2f(30.f, -15.f));
    shape.setPoint(2, Vector2f(30.f, -10.f));
    shape.setPoint(3, Vector2f(-60.f, -10.f));

    shape.setFillColor(Color(10, 238, 223));

}

LaserShape::~LaserShape()
{
}