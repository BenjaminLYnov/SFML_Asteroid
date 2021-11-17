#include "Laser.hpp"

Laser::Laser()
{
    laserImage = new SfmlImage("ressources/images/laser.png", 389, 129, 0, 0);
    laserImage->sprite.setScale(0.2, 0.2);

    speedMove = 0;
    speedMove = 20;
    sent = false;
    keyJ = true;
}

Laser::~Laser()
{
    // delete laserImage;
}

void Laser::inputSendLaser(Event &event, Vector2f target, float rotation)
{
    if (Keyboard::isKeyPressed(Keyboard::J) && keyJ)
    {
        sent = true;
        keyJ = false;
        laserImage->sprite.setPosition(target);
        laserImage->sprite.setRotation(rotation);
        dir = Vector2f((float)cos(rotation * PI / 180), (float)sin(rotation * PI / 180)); // Vecteur Already Normalized
    }
    if (!Keyboard::isKeyPressed(Keyboard::J))
        keyJ = true;
}

void Laser::laserMove()
{
    if (sent)
        laserImage->sprite.move(dir * speedMove);
}

void Laser::Update()
{
    laserMove();
}

void Laser::draw(RenderWindow &window) const
{
    laserImage->draw(window);
}