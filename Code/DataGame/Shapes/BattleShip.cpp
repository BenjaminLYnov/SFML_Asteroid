#include "BattleShip.hpp"

BattleShip::BattleShip()
{
    shape.setPointCount(10);

    shape.setPoint(0, sf::Vector2f(-50.f, -30.f));
    shape.setPoint(1, sf::Vector2f(-50.f, 60.f));
    shape.setPoint(2, sf::Vector2f(-30.f, 15.f));
    shape.setPoint(3, sf::Vector2f(0.f, 120.f));
    shape.setPoint(4, sf::Vector2f(50.f, -30.f));
    shape.setPoint(5, sf::Vector2f(50.f, 60.f));
    shape.setPoint(6, sf::Vector2f(0.f, -30.f));
    shape.setPoint(7, sf::Vector2f(-50.f, 60.f));
    shape.setPoint(8, sf::Vector2f(-50.f, -30.f));
    shape.setPoint(9, sf::Vector2f(-30.f, 15.f));

    shape.setPosition(960, 540);
    shape.setScale(sf::Vector2f(0.3f, 0.3f));

    SetCentralOrigin();

    texture.loadFromFile("./ressources/Texture/BattleShipTexture.png");
    shape.setTexture(&texture);
}

BattleShip::~BattleShip()
{
}
