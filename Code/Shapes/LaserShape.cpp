#include "LaserShape.hpp"

LaserShape::LaserShape()
{

    shape.setPointCount(4);

    shape.setPoint(0, Vector2f(0.f, 50.f));
    shape.setPoint(1, Vector2f(90.f, 50.f));
    shape.setPoint(2, Vector2f(90.f, 55.f));
    shape.setPoint(3, Vector2f(0.f, 55.f));
    

    shape.setFillColor(Color(10, 238, 223));

    shape.setOrigin(Vector2f(0.f, 52.5f));

}

LaserShape::~LaserShape()
{
}
