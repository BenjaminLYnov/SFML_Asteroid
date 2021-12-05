#include "Laser.hpp"
#include "../../Wraparound/Wraparound.hpp"

Laser::Laser()
{
}

Laser::Laser(sf::Vector2f target, float rotation, float speedMove)
{
    this->speedMove = speedMove;
    laserShape.GetShape().setPosition(target);
    laserShape.GetShape().setRotation(rotation);
    direction = sf::Vector2f((float)cos(rotation * PI / 180), (float)sin(rotation * PI / 180));
    direction = Vector2D::Normalized(direction);
}

Laser::~Laser()
{
}

void Laser::Update()
{
    LaserMove();
    lifeTime.UpTime();
    Wraparound::MirorSide(GetShape());

}

void Laser::Draw(sf::RenderWindow &window) const
{
    laserShape.Draw(window);
}

sf::ConvexShape &Laser::GetShape()
{
    return laserShape.GetShape();
}

void Laser::LaserMove()
{
    GetShape().move(direction * speedMove);
}

