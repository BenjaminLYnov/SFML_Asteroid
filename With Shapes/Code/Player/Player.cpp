#include "Player.hpp"

Player::Player()
{
     // ship.rectangle.setScale(10, 1);
}

Player::~Player()
{
}

void Player::input(Event &event)
{
     move.inputMove(event);
     move.inputRotation(event);
     skills.input(event);
     if (skills.lasers.size() > 0)
          skills.lasers[skills.lasers.size() - 1].inputSendLaser(event, ship.shape.getPosition(), ship.shape.getRotation() + 90);
}

void Player::Update()
{
     move.moveSprite(ship.shape);
     move.rotationSprite(ship.shape);

     skills.Update();
}

void Player::draw(RenderWindow &window)
{
     // rectangle.setSize(Vector2f(100, 100));
     // ship.draw(window);
     window.draw(ship.shape);
     // window.draw(ship.getShape());
     skills.draw(window);
}
