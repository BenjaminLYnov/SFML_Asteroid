#include "AsteroidShape.h"

BattleAsteroid::BattleAsteroid()
{
    int randomType = rand() % 3;

    switch (randomType) {
        case 0:
            type1();
        case 1:
            type2();
        case 3:
            type3();
    }
}

BattleAsteroid::~BattleAsteroid()
{
}

void BattleAsteroid::type1() {

    ConvexShape shapeAsteroid(7);

    shapeAsteroid.setPoint(0, Vector2(0.356f, -0.096f));
    shapeAsteroid.setPoint(1, Vector2(-0.072f, -0.384f));
    shapeAsteroid.setPoint(2, Vector2(-0.387f, -0.188f));
    shapeAsteroid.setPoint(3, Vector2(-0.462f, 0.192f));
    shapeAsteroid.setPoint(4, Vector2(-0.079f, 0.459f));
    shapeAsteroid.setPoint(5, Vector2(0.264f, 0.332f));
    shapeAsteroid.setPoint(6, Vector2(0.14f, 0.065f));

    shapeAsteroid.setFillColor(Color(180, 100, 40));
    shapeAsteroid.setScale(Vector2f(0.5f, 0.5f));
}

void BattleAsteroid::type2() {

    sf::ConvexShape shape(6);

    shape.setPoint(0, Vector2(-0.253f, -0.336f));
    shape.setPoint(1, Vector2(-0.551f, -0.051f));
    shape.setPoint(2, Vector2(-0.236f, 0.014f));
    shape.setPoint(3, Vector2(0.116f, 0.223f));
    shape.setPoint(4, Vector2(0.168f, -0.103f));
    shape.setPoint(5, Vector2(-0.072f, -0.058f));

    shapeAsteroid.setFillColor(Color(180, 100, 40));
    shapeAsteroid.setScale(Vector2f(0.5f, 0.5f));
}


void BattleAsteroid::type3() {

    sf::ConvexShape shape(8);

    shape.setPoint(0, Vector2(-0.166f, 0.243f));
    shape.setPoint(1, Vector2(-0.438f, 0.116f));
    shape.setPoint(2, Vector2(-0.37f, -0.288f));
    shape.setPoint(3, Vector2(-0.027f, -0.38f));
    shape.setPoint(4, Vector2(0.387f, -0.233f));
    shape.setPoint(5, Vector2(0.115f, -0.158f));
    shape.setPoint(6, Vector2(0.295f, 0.192f));
    shape.setPoint(7, Vector2(-0.221f, -0.154f));

    shapeAsteroid.setFillColor(Color(180, 100, 40));
    shapeAsteroid.setScale(Vector2f(0.25f, 0.25f));
}

void BattleAsteroid::breakAsteroid() {
    shapeAsteroid.setScale(Vector2f(0.25f, 0.25f));
}

ConvexShape BattleAsteroid::getShapeAsteroid()
{
    return shapeAsteroid;
}
void BattleAsteroid::draw(RenderWindow &window) const
{
    window.draw(shapeAsteroid);
}
