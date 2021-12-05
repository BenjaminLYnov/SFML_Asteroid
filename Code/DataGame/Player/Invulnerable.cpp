#include "Invulnerable.hpp"

Invulnerable::Invulnerable()
{
    isInvulnerable = false;
    blinkerDelay = 0.1f;
    invulnerableDelay = 1.f;
}

Invulnerable::~Invulnerable()
{
}

void Invulnerable::BecomeInvulnerable()
{
    isInvulnerable = true;
}

void Invulnerable::InvulnerableBlinker(sf::ConvexShape &shape)
{
    if (isInvulnerable)
    {
        blinkerTimer.UpTime();
        invulnerableTimer.UpTime();

        if (blinkerTimer.GetTime() > blinkerDelay)
            Visible(shape);
        else
            Invisible(shape);

        if (blinkerTimer.GetTime() > blinkerDelay * 2)
            blinkerTimer.Reset();

        if (invulnerableTimer.GetTime() > invulnerableDelay)
        {
            Visible(shape);
            isInvulnerable = false;
            invulnerableTimer.Reset();
        }
    }
}

void Invulnerable::Invisible(sf::ConvexShape &shape)
{
    shape.setFillColor(sf::Color(250, 250, 250, 0));
}

void Invulnerable::Visible(sf::ConvexShape &shape)
{
    shape.setFillColor(sf::Color(250, 250, 250, 255));
}
