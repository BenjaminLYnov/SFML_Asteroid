#include "Skills.hpp"

Skills::Skills()
{
    keyJ = true;
}

Skills::~Skills()
{
    // delete lasers;
}

void Skills::input(Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::J) && keyJ)
    {
        keyJ = false;
        lasers.push_back(Laser());
        // cout <<lasers.size()<< "\n";
    }
    if (!Keyboard::isKeyPressed(Keyboard::J))
        keyJ = true;
}

void Skills::Update()
{
    for (int i = 0; i < lasers.size(); i++)
        lasers[i].laserMove();
}

void Skills::draw(RenderWindow &window) const
{
    for (int i = 0; i < lasers.size(); i++)
        // lasers[i].draw(window);
        window.draw(lasers[i].laserShape.shape);
}