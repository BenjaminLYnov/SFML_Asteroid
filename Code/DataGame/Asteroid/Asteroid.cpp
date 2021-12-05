#include "Asteroid.hpp"
#include "../Math/RandomNumber.hpp"
#include "../Math/Vector2D.hpp"
#include "../Wraparound/Wraparound.hpp"
#include <iostream>

Asteroid::Asteroid()
{
    size = 1;
    SetSize(size);
    SetBangSound(size);
    direction = sf::Vector2f(RandomNumber::RandomFloat(-1, 1), RandomNumber::RandomFloat(-1, 1));
    direction = Vector2D::Normalized(direction);
    speedMove = 3;
}

Asteroid::Asteroid(int size)
{
    this->size = size;
    SetSize(size);
    SetBangSound(size);
    direction = sf::Vector2f(RandomNumber::RandomFloat(-1, 1), RandomNumber::RandomFloat(-1, 1));
    direction = Vector2D::Normalized(direction);
    speedMove = 3;
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update()
{
    Move();
    Wraparound::MirorSide(GetShape());
}

void Asteroid::Draw(sf::RenderWindow &window) const
{
    asteroidShape.Draw(window);
}

void Asteroid::SetSize(int size)
{
    // There is 3 size about asteroid : small, medium and large
    // By default scale is 1, 1
    // Large asteroid dont need to be rescale

    if (size == 2)
        asteroidShape.SetScale(0.6f, 0.6f); // Medium
    else if (size == 3)
        asteroidShape.SetScale(0.3f, 0.3f); // Small
}

void Asteroid::SetBangSound(int size)
{
    if (size == 1)
        bangAsteorid = new SfmlAudio("ressources/Sound/Asteroid79 sound/bangLarge.wav"); // Bang Large
    if (size == 2)
        bangAsteorid = new SfmlAudio("ressources/Sound/Asteroid79 sound/bangMedium.wav"); // Bang Medium
    else if (size == 3)
        bangAsteorid = new SfmlAudio("ressources/Sound/Asteroid79 sound/bangSmall.wav"); // Bang Small
}

void Asteroid::PlayBangSound()
{
    bangAsteorid->Play();
}

int &Asteroid::GetSize()
{
    return size;
}

sf::ConvexShape &Asteroid::GetShape()
{
    return asteroidShape.GetShape();
}

void Asteroid::Move()
{
    GetShape().move(direction * speedMove);
}
