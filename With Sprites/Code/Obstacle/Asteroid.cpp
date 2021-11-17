#include "Asteroid.hpp"

Asteroid::Asteroid()
{
    // Random float generator
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_real_distribution<> rand(-5, 5);

    mediumAsteroidImage = new SfmlImage("ressources/images/Asteroid/mediumAsteroid1.png", 175, 162, 500, 500);
    speedMove = 2;

    mediumDir.y = rand(generator);
    mediumDir.x = rand(generator);
}

Asteroid::~Asteroid()
{
    delete mediumAsteroidImage;
    delete smallAsteroidImage1;
    delete smallAsteroidImage2;
    delete verySmallAsteroidImage1[2];
    delete verySmallAsteroidImage2[2];
}

void Asteroid::asteroidMove()
{
    mediumAsteroidImage->sprite.move(mediumDir * speedMove);
}

void Asteroid::Update()
{
    asteroidMove();
}

void Asteroid::draw(RenderWindow &window) const
{
    mediumAsteroidImage->draw(window);
}