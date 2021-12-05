#include "Skills.hpp"
#include <SFML/Window/Keyboard.hpp>

Skills::Skills()
{
    keyJ = true;
    keyK = true;
    lifeExpectancyLaser = 0.5f;
    laserSound = new SfmlAudio("ressources/Sound/Asteroid79 sound/fire.wav");
}

Skills::~Skills()
{
}

void Skills::Update()
{
    DestroyLaser();
    for (int i = 0; i < lasers.size(); i++)
        lasers[i].Update();
}

void Skills::Draw(sf::RenderWindow &window) const
{
    for (int i = 0; i < lasers.size(); i++)
        lasers[i].Draw(window);
}

std::vector<Laser> &Skills::GetLasers()
{
    return lasers;
}

Laser &Skills::GetLastLasers()
{
    return lasers[lasers.size() - 1];
}

int Skills::GetLasersQuantity()
{
    return lasers.size();
}

void Skills::InputLaser(sf::Vector2f target, float rotation, float speedMove)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && keyJ)
    {
        laserSound->Play();
        keyJ = false;
        lasers.push_back(Laser(target, rotation, speedMove));
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        keyJ = true;
}

void Skills::InputTeleportation(sf::ConvexShape &shape)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && keyK)
    {
        keyK = false;
        teleportation.InstantTeleportation(shape);
    }

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        keyK = true;
}

void Skills::DestroyLaser()
{
    for (int i = lasers.size() - 1; i >= 0; i--)
        if (lasers[i].lifeTime.GetTime() > lifeExpectancyLaser)
            if (GetLasers().size() > 0)
                lasers.erase(lasers.begin() + i);
}