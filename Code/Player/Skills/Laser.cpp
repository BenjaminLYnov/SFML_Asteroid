#include "Laser.hpp"
#include <tgmath.h>

Laser::Laser()
{
    speedMove = 0;
    speedMove = 20;
    sent = false;
    keySpace = true;
}

Laser::~Laser()
{}

void Laser::inputSendLaser(Event &event, Vector2f target, float rotation)
{
    if (Keyboard::isKeyPressed(Keyboard::Space) && keySpace)
    {
        sent = true;
        keySpace = false;
        laserShape.shape.setPosition(target);
        laserShape.shape.setRotation(rotation);
        direction = Vector2f((float)cos(rotation * PI / 180), (float)sin(rotation * PI / 180)); 
        direction = Vector2D::Normalized(direction);
    }
    if (!Keyboard::isKeyPressed(Keyboard::Space))
        keySpace = true;
}

void Laser::laserMove()
{
    if (sent)
        laserShape.shape.move(direction * speedMove);
}

void Laser::Update()
{
    laserMove();
}

void Laser::draw(RenderWindow &window) const
{}