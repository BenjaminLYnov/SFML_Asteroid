#include "Asteroidshape.hpp"
#include "../Math/RandomNumber.hpp"

AsteroidShape::AsteroidShape()
{
    modele = RandomNumber::RandomInt(1, 3);
    SetAsteroidOutsideScreen();
    LoadModele();
    shape.setFillColor(sf::Color(123, 125, 125));
}

AsteroidShape::~AsteroidShape()
{
}

void AsteroidShape::SetAsteroidOutsideScreen()
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

void AsteroidShape::LoadModele()
{
    if (modele == 1)
        Modele1();
    else if (modele == 2)
        Modele2();
    else if (modele == 3)
        Modele3();
}

void AsteroidShape::Modele1()
{
    shape.setPointCount(5);
    shape.setPoint(0, sf::Vector2f(-62.571f, -15.714f));
    shape.setPoint(1, sf::Vector2f(-28.000f, -68.286f));
    shape.setPoint(2, sf::Vector2f(41.143f, -48.571f));
    shape.setPoint(3, sf::Vector2f(31.143f, 23.143f));
    shape.setPoint(4, sf::Vector2f(-37.143f, 25.429f));
}

void AsteroidShape::Modele2()
{
    shape.setPointCount(4);
    shape.setPoint(0, sf::Vector2f(-60.857f, -31.714f));
    shape.setPoint(1, sf::Vector2f(14.571f, -81.143f));
    shape.setPoint(2, sf::Vector2f(8.857f, 48.000f));
    shape.setPoint(3, sf::Vector2f(-45.143f, 61.429f));
}

void AsteroidShape::Modele3()
{
    shape.setPointCount(4);
    shape.setPoint(0, sf::Vector2f(-75.714f, -9.714f));
    shape.setPoint(1, sf::Vector2f(77.714f, -75.714f));
    shape.setPoint(2, sf::Vector2f(57.429f, 65.429f));
    shape.setPoint(3, sf::Vector2f(-25.714f, 40.286f));
}
