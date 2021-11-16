#include "Player.hpp"

Player::Player()
{
     vaisseauSprite = new SfmlImage("ressources/images/Vaisseau.png", 25, 21, 183, 228);
     vaisseauSprite->sprite.setScale(1, 1);
}

Player::~Player()
{
     delete vaisseauSprite;
}

void Player::input(Event &event)
{
     move.inputMove(event);
     move.inputRotation(event);
     skills.input(event);
     if (skills.lasers.size() > 0)
          skills.lasers[skills.lasers.size() - 1].inputSendLaser(event, vaisseauSprite->sprite.getPosition(), vaisseauSprite->sprite.getRotation());
}

void Player::Update()
{
     move.moveSprite(vaisseauSprite->sprite);
     move.rotationSprite(vaisseauSprite->sprite);

     skills.Update();
}

void Player::draw(RenderWindow &window) const
{
     vaisseauSprite->draw(window);
     skills.draw(window);
}
