#include "OVNIShape.hpp"
#include "../Math/RandomNumber.hpp"

OVNIShape::OVNIShape()
{
    shape.setPointCount(27);

    shape.setPoint(0, sf::Vector2f(-12.286f, -2.286f));
    shape.setPoint(1, sf::Vector2f(-10.000f, -6.857f));
    shape.setPoint(2, sf::Vector2f(-8.571f, -10.286f));
    shape.setPoint(3, sf::Vector2f(-6.000f, -12.000f));
    shape.setPoint(4, sf::Vector2f(-2.857f, -13.429f));
    shape.setPoint(5, sf::Vector2f(2.000f, -15.429f));
    shape.setPoint(6, sf::Vector2f(4.571f, -14.857f));
    shape.setPoint(7, sf::Vector2f(8.857f, -13.143f));
    shape.setPoint(8, sf::Vector2f(12.286f, -10.857f));
    shape.setPoint(9, sf::Vector2f(14.000f, -9.143f));
    shape.setPoint(10, sf::Vector2f(16.286f, -4.571f));
    shape.setPoint(11, sf::Vector2f(16.571f, -2.286f));
    shape.setPoint(12, sf::Vector2f(25.429f, -2.857f));
    shape.setPoint(13, sf::Vector2f(24.571f, 2.286f));
    shape.setPoint(14, sf::Vector2f(22.571f, 7.143f));
    shape.setPoint(15, sf::Vector2f(17.714f, 10.286f));
    shape.setPoint(16, sf::Vector2f(8.857f, 13.429f));
    shape.setPoint(17, sf::Vector2f(3.429f, 13.429f));
    shape.setPoint(18, sf::Vector2f(-5.429f, 13.143f));
    shape.setPoint(19, sf::Vector2f(-12.000f, 10.571f));
    shape.setPoint(20, sf::Vector2f(-17.143f, 7.143f));
    shape.setPoint(21, sf::Vector2f(-19.143f, 5.143f));
    shape.setPoint(22, sf::Vector2f(-22.571f, 1.714f));
    shape.setPoint(23, sf::Vector2f(-23.714f, -1.429f));
    shape.setPoint(24, sf::Vector2f(-23.714f, -2.571f));
    shape.setPoint(25, sf::Vector2f(-12.571f, -2.000f));
    shape.setPoint(26, sf::Vector2f(16.857f, -2.000f));

    shape.setFillColor(sf::Color(0, 250, 0));
    SetCentralOrigin();
    SetShapeOutsideScreen();
}

OVNIShape::~OVNIShape()
{
}

void OVNIShape::SetShapeOutsideScreen()
{
    float posX, posY;
    if (RandomNumber::RandomInt(0, 1) == 0)
        posX = RandomNumber::RandomInt(-100, 0);
    else
        posX = RandomNumber::RandomInt(1920, 2000);

    if (RandomNumber::RandomInt(0, 1) == 0)
        posY = RandomNumber::RandomInt(-100, 0);
    else
        posY = RandomNumber::RandomInt(1080, 1200);

    shape.setPosition(sf::Vector2f(posX, posY));
}