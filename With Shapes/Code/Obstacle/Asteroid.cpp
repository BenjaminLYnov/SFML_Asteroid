#include "Asteroid.hpp"

Asteroid::Asteroid()
{

//    // Random float generator
//    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
//    default_random_engine generator(seed);
//    uniform_real_distribution<> rand(-5, 5);

//    // mediumAsteroidImage = new SfmlImage("ressources/images/Asteroid/mediumAsteroid1.png", 175, 162, 500, 500);
//    speedMove = 2;

//    mediumDir.y = rand(generator);
//    mediumDir.x = rand(generator);
}

Asteroid::~Asteroid()
{}

void Asteroid::asteroidMove()
{

}

void Asteroid::Update()
{
    asteroidMove();
}

void Asteroid::draw(RenderWindow &window) const
{
    window.draw(asteroid.shapeAsteroid);
}
