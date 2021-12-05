#include "Player.hpp"
#include "../Wraparound/Wraparound.hpp"

Player::Player()
{
     hp = 3;
     skills = new Skills();
     hurtSound = new SfmlAudio("ressources/Sound/getHurt.wav");
}

Player::~Player()
{
     delete skills;
     delete hurtSound;
}

void Player::Update()
{
     Input();
     invulnerable.InvulnerableBlinker(ship.GetShape());
     move.MoveShape(ship.GetShape());
     move.RotationShape(ship.GetShape());
     Wraparound::MirorSide(ship.GetShape());
     skills->Update();
}

void Player::Draw(sf::RenderWindow &window) const
{
     ship.Draw(window);
     skills->Draw(window);
}

int &Player::GetHp()
{
     return hp;
}

sf::ConvexShape &Player::GetShape()
{
     return ship.GetShape();
}

Skills &Player::GetSkills()
{
     return *skills;
}

void Player::Input()
{
     move.InputMove();
     move.InputRotation();
     skills->InputLaser(ship.GetShape().getPosition(), ship.GetShape().getRotation() + 90, 20);
     skills->InputTeleportation(ship.GetShape());
}

void Player::GetHurt()
{
     if (!invulnerable.isInvulnerable)
     {
          invulnerable.BecomeInvulnerable();
          hurtSound->Play();
          hp--;
     }
}
