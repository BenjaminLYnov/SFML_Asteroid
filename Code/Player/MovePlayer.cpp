#include "MovePlayer.hpp"

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

void MovePlayer::inputMove(Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::S))
        moveForward = true;
    else
        moveForward = false;
}

void MovePlayer::inputRotation(Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::Q))
        rotationRight = true;
    else
        rotationRight = false;

    if (Keyboard::isKeyPressed(Keyboard::D))
        rotationLeft = true;
    else
        rotationLeft = false;
}

void MovePlayer::moveSprite(ConvexShape &sprite)
{
    if (moveForward)
        sprite.move(direction * speedMove);
}

void MovePlayer::rotationSprite(ConvexShape &sprite)
{
    if (rotationLeft)
        sprite.rotate(speedRotation);
    if (rotationRight)
        sprite.rotate(-speedRotation);
    direction = Vector2f((float)cos((sprite.getRotation() + 90) * PI / 180), (float)sin((sprite.getRotation() + 90) * PI / 180));
    direction = Vector2D::Normalized(direction);
}
