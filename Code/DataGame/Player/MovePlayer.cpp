#include "MovePlayer.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <math.h>

MovePlayer::MovePlayer()
{
    moveForward = false;
    rotationLeft = false;
    rotationRight = false;
    speedMove = 5;
    speedRotation = 10;
}

MovePlayer::MovePlayer(float SpeedMove)
{
    moveForward = false;
    rotationLeft = false;
    rotationRight = false;
    speedMove = SpeedMove;
}

MovePlayer::~MovePlayer()
{
}

void MovePlayer::InputMove()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        moveForward = true;
    else
        moveForward = false;
}

void MovePlayer::InputRotation()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        rotationRight = true;
    else
        rotationRight = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        rotationLeft = true;
    else
        rotationLeft = false;
}

void MovePlayer::MoveShape(sf::ConvexShape &shape)
{
    if (moveForward)
        shape.move(direction * speedMove);
}

void MovePlayer::RotationShape(sf::ConvexShape &sprite)
{
    if (rotationLeft)
        sprite.rotate(speedRotation);
    if (rotationRight)
        sprite.rotate(-speedRotation);
    direction = sf::Vector2f((float)cos((sprite.getRotation() + 90) * PI / 180), (float)sin((sprite.getRotation() + 90) * PI / 180));
    direction = Vector2D::Normalized(direction);
}
