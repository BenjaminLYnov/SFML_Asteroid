#include "MovePlayer.hpp"

MovePlayer::MovePlayer()
{
    moveUp = false;
    moveDown = false;
    moveLeft = false;
    moveRight = false;
    rotationLeft = false;
    rotationRight = false;

    speedMove = 5;
    speedRotation = 10;
}

MovePlayer::MovePlayer(double SpeedMove)
{
    moveUp = false;
    moveDown = false;
    moveLeft = false;
    moveRight = false;
    rotationLeft = false;
    rotationRight = false;

    speedMove = SpeedMove;
}

MovePlayer::~MovePlayer()
{
}

void MovePlayer::inputMove(Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::Z))
        moveUp = true;
    else
        moveUp = false;

    if (Keyboard::isKeyPressed(Keyboard::S))
        moveDown = true;
    else
        moveDown = false;

    if (Keyboard::isKeyPressed(Keyboard::D))
        moveRight = true;
    else
        moveRight = false;

    if (Keyboard::isKeyPressed(Keyboard::Q))
        moveLeft = true;
    else
        moveLeft = false;
}

void MovePlayer::inputRotation(Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::Right))
        rotationRight = true;
    else
        rotationRight = false;

    if (Keyboard::isKeyPressed(Keyboard::Left))
        rotationLeft = true;
    else
        rotationLeft = false;
}

void MovePlayer::moveSprite(ConvexShape &sprite)
{
    if (moveUp)
        sprite.move(0, -speedMove);
    if (moveDown)
        sprite.move(0, speedMove);
    if (moveLeft)
        sprite.move(-speedMove, 0);
    if (moveRight)
        sprite.move(speedMove, 0);
}

void MovePlayer::rotationSprite(ConvexShape &sprite)
{
    if (rotationLeft)
        sprite.rotate(speedRotation);
    if (rotationRight)
        sprite.rotate(-speedRotation);
}
