#ifndef ASTEROIDSHAPE_H
#define ASTEROIDSHAPE_H

#include <SFML/Graphics.hpp>
using namespace sf;

class BattleAsteroid
{
private:
    Vector2f dirAsteroid;
public:
    BattleAsteroid();
    ~BattleAsteroid();

    ConvexShape shapeAsteroid;
    ConvexShape getShapeAsteroid();

    void type1();
    void type2();
    void type3();
    void breakAsteroid();
    void draw(RenderWindow &window) const;
};

#endif // ASTEROIDSHAPE_H
