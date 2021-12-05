#include "AsteroidEngine.hpp"

AsteroidEngine::AsteroidEngine()
{
}

AsteroidEngine::~AsteroidEngine()
{
}

void AsteroidEngine::Update()
{
    for (Asteroid &asteroid : asteroids)
        asteroid.Update();
}

void AsteroidEngine::Draw(sf::RenderWindow &window) const
{
    for (const Asteroid &asteroid : asteroids)
        asteroid.Draw(window);
}

void AsteroidEngine::CreateAsteroid()
{
    asteroids.push_back(Asteroid());
}

void AsteroidEngine::CreateAsteroid(char size)
{
    asteroids.push_back(Asteroid(size));
}

void AsteroidEngine::DestroyAsteroid(int indice)
{
    asteroids.erase(asteroids.begin() + indice);
}

Asteroid &AsteroidEngine::GetAsteroid(int indice)
{
    return asteroids[indice];
}

Asteroid &AsteroidEngine::GetLastAsteroid()
{
    return asteroids[asteroids.size() - 1];
}

std::vector<Asteroid> &AsteroidEngine::GetAsteroids()
{
    return asteroids;
}