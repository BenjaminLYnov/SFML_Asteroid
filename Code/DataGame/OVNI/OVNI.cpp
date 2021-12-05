#include "OVNI.hpp"
#include "../Math/Vector2D.hpp"

OVNI::OVNI()
{
    speedMove = 4;

}

OVNI::~OVNI()
{
}

void OVNI::MoveOnTarget(sf::Vector2f target)
{
    if (Vector2D::Distance(GetShape().getPosition(), target) > 20)
    {
        direction = target - GetShape().getPosition();
        direction = Vector2D::Normalized(direction);
        GetShape().move(direction * speedMove);
    }
}

void OVNI::Draw(sf::RenderWindow &window) const
{
    ovniShape.Draw(window);
}

sf::ConvexShape &OVNI::GetShape()
{
    return ovniShape.GetShape();
}

