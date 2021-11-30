#include "Asteroid.hpp"

Asteroid::Asteroid()
{
    deadTime = 20;
    asteroidsLarge.push_back(AsteroidLarge());
    asteroidsMedium.push_back(AsteroidMedium());
    asteroidsSmall.push_back(AsteroidSmall());

    // Lauch chrono
    createNextAsteroidSmallTime.start();
    createNextAsteroidMediumTime.start();
    createNextAsteroidLargeTime.start();

    createNextAsteroidSmall = 0.2f;
    createNextAsteroidMedium = 0.2f;
    createNextAsteroidLarge = 0.2f;
    // createNextAsteroidSmall = RandomNumber::RandomFloat(5, 10);
    // createNextAsteroidMedium = RandomNumber::RandomFloat(5, 10);
    // createNextAsteroidLarge = RandomNumber::RandomFloat(5, 10);
}

Asteroid::~Asteroid()
{
}

// void Asteroid::DrawAsteroid(vector<AsteroidGear> asteroids, RenderWindow &window) const
// {
//     for (int i = 0; i <= asteroids.size(); i++)
//         asteroids[i].Draw(window);
// }

// void Asteroid::Draw(RenderWindow &window) const
// {
//     for (int i = 0; i < asteroidsLarge.size(); i++)
//         asteroidsLarge[i].Draw(window);
//     for (int i = 0; i < asteroidsMedium.size(); i++)
//         asteroidsMedium[i].Draw(window);
//     for (int i = 0; i < asteroidsSmall.size(); i++)
//         asteroidsSmall[i].Draw(window);
// }

void Asteroid::Update()
{
    for (int i = 0; i < asteroidsLarge.size(); i++)
        asteroidsLarge[i].Update();
    for (int i = 0; i < asteroidsMedium.size(); i++)
        asteroidsMedium[i].Update();
    for (int i = 0; i < asteroidsSmall.size(); i++)
        asteroidsSmall[i].Update();

    DestroyAsteroid();
    CreateAsteroid();
}

void Asteroid::CreateAsteroid()
{
    createNextAsteroidSmallTime.upTime();
    createNextAsteroidMediumTime.upTime();
    createNextAsteroidLargeTime.upTime();

    for (int i = 0; i < asteroidsLarge.size(); i++)
    {
        if (createNextAsteroidLargeTime.getTime() > createNextAsteroidLarge)
        {
            asteroidsLarge.push_back(AsteroidLarge());
            // createNextAsteroidLarge = RandomNumber::RandomFloat(0.5f, 1);
            createNextAsteroidLargeTime.reset();
        }
    }

    for (int i = 0; i < asteroidsMedium.size(); i++)
    {
        if (createNextAsteroidMediumTime.getTime() > createNextAsteroidMedium)
        {
            asteroidsMedium.push_back(AsteroidMedium());
            // createNextAsteroidMedium = RandomNumber::RandomFloat(0.5f, 1);
            createNextAsteroidMediumTime.reset();
        }
    }

    for (int i = 0; i < asteroidsSmall.size(); i++)
    {
        if (createNextAsteroidSmallTime.getTime() > createNextAsteroidSmall)
        {
            asteroidsSmall.push_back(AsteroidSmall());
            // createNextAsteroidSmall = RandomNumber::RandomFloat(0.5f, 1);
            createNextAsteroidSmallTime.reset();
        }
    }
}

void Asteroid::DestroyAsteroid()
{
    for (int i = 0; i < asteroidsLarge.size(); i++)
        if (asteroidsLarge[i].lifeTime.getTime() > deadTime)
            asteroidsLarge.erase(asteroidsLarge.begin() + i);

    for (int i = 0; i < asteroidsMedium.size(); i++)
        if (asteroidsMedium[i].lifeTime.getTime() > deadTime)
            asteroidsMedium.erase(asteroidsMedium.begin() + i);

    for (int i = 0; i < asteroidsSmall.size(); i++)
        if (asteroidsSmall[i].lifeTime.getTime() > deadTime)
            asteroidsSmall.erase(asteroidsSmall.begin() + i);
}

template <typename T>
void DrawAsteroid(const vector<T> asteroids, RenderWindow &window)
{
    for (const auto asteroid : asteroids)
        asteroid.Draw(window);
}

void Asteroid::Draw(RenderWindow &window) const
{
    DrawAsteroid(asteroidsLarge, window);
    DrawAsteroid(asteroidsMedium, window);
    DrawAsteroid(asteroidsSmall, window);
}

// void Asteroid::DrawAsteroid(type asteroids, RenderWindow &window) const
// {
//     for (int i = 0; i < asteroids.size(); i++)
//         asteroids[i].Draw(window);
// }
