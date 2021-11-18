#include "StartBattleShonenShipOverdrive.hpp"

StartBattleShonenShipOverdrive::StartBattleShonenShipOverdrive()
{
    shape.setPointCount(10);

    shape.setPoint(0, Vector2f(-50.f, -30.f));
    shape.setPoint(1, Vector2f(-50.f, 60.f));
    shape.setPoint(2, Vector2f(-30.f, 15.f));
    shape.setPoint(3, Vector2f(0.f, 120.f));
    shape.setPoint(4, Vector2f(50.f, -30.f));
    shape.setPoint(5, Vector2f(50.f, 60.f));
    shape.setPoint(6, Vector2f(0.f, -30.f));
    shape.setPoint(7, Vector2f(-50.f, 60.f));
    shape.setPoint(8, Vector2f(-50.f, -30.f));
    shape.setPoint(9, Vector2f(-30.f, 15.f));

    shape.setFillColor(Color(100, 250, 50));
    shape.setPosition(Vector2f(300.f, 300.f));
    shape.setScale(Vector2f(0.5f, 0.5f));

    shape.setOrigin(Vector2f(0.f, 45.f));

    
}

StartBattleShonenShipOverdrive::~StartBattleShonenShipOverdrive()
{
}

ConvexShape StartBattleShonenShipOverdrive::getShape()
{
    return shape;
}
void StartBattleShonenShipOverdrive::draw(RenderWindow &window) const
{
    window.draw(shape);
}