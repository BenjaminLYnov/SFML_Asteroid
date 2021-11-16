#include "Wall.hpp"

Wall::Wall()
{
}

Wall::~Wall()
{
}

void Wall::isWall(Sprite &sprite1, Sprite &sprite2)
{
     if (Collision::PixelPerfectTest(sprite1, sprite2))
     {
          setNewPosition(sprite1, sprite2);
     }
}

void Wall::setNewPosition(Sprite &sprite1, Sprite &sprite2)
{
     cornerRadius = Radius::radiusCorner(sprite2);
     cornerRadiusUpLeft = Radius::radiusBeetween2Vector(sprite2.getPosition().x + sprite2.getTextureRect().width * sprite2.getScale().x / 2, sprite2.getPosition().y + sprite2.getTextureRect().height * sprite2.getScale().y / 2, sprite1.getPosition().x, sprite1.getPosition().y);
     cornerRadiusUpRight = Radius::radiusBeetween2Vector(sprite2.getPosition().x + sprite2.getTextureRect().width * sprite2.getScale().x / 2, sprite2.getPosition().y + sprite2.getTextureRect().height * sprite2.getScale().y / 2, sprite1.getPosition().x + sprite1.getTextureRect().width * sprite1.getScale().x, sprite1.getPosition().y);
     cornerRadiusDownLeft = Radius::radiusBeetween2Vector(sprite2.getPosition().x + sprite2.getTextureRect().width * sprite2.getScale().x / 2, sprite2.getPosition().y + sprite2.getTextureRect().height * sprite2.getScale().y / 2, sprite1.getPosition().x, sprite1.getPosition().y + sprite1.getTextureRect().height * sprite1.getScale().y);
     cornerRadiusDownRight = Radius::radiusBeetween2Vector(sprite2.getPosition().x + sprite2.getTextureRect().width * sprite2.getScale().x / 2, sprite2.getPosition().y + sprite2.getTextureRect().height * sprite2.getScale().y / 2, sprite1.getPosition().x + sprite1.getTextureRect().width * sprite1.getScale().x, sprite1.getPosition().y + sprite1.getTextureRect().height * sprite1.getScale().y);
     bilateralRadius = (360 - (cornerRadius * 4)) / 2;

     // Left
     if ((cornerRadiusUpRight >= (cornerRadius + bilateralRadius) && cornerRadiusUpRight <= (cornerRadius * 3 + bilateralRadius)) || (cornerRadiusDownRight >= (cornerRadius + bilateralRadius) && cornerRadiusDownRight <= (cornerRadius * 3 + bilateralRadius)))
     {
          cout << cornerRadiusDownRight << " >= " << (cornerRadius + bilateralRadius) << " && " << cornerRadiusDownRight << " <= " << (cornerRadius * 3 + bilateralRadius) << "\n";
          // cout << "left\n";
          sprite1.setPosition(sprite2.getPosition().x - sprite1.getTextureRect().width * sprite1.getScale().x, sprite1.getPosition().y);
          // sprite1.move(-3, 0);
          }
     // Right
     if ((cornerRadiusUpLeft >= (cornerRadius * 3 + bilateralRadius * 2) || cornerRadiusUpLeft <= cornerRadius) || (cornerRadiusDownLeft >= (cornerRadius * 3 + bilateralRadius * 2) || cornerRadiusDownLeft <= cornerRadius))
     {
          // cout << "right\n";
          sprite1.setPosition(sprite2.getPosition().x + sprite2.getTextureRect().width * sprite2.getScale().x, sprite1.getPosition().y);
          // sprite1.move(3, 0);
     }
     // Up
     if ((cornerRadiusDownLeft >= cornerRadius && cornerRadiusDownLeft <= (cornerRadius + bilateralRadius)) || (cornerRadiusDownRight >= cornerRadius && cornerRadiusDownRight <= (cornerRadius + bilateralRadius)))
     {
          // cout << "up\n";
          sprite1.setPosition(sprite1.getPosition().x, sprite2.getPosition().y - sprite1.getTextureRect().height * sprite1.getScale().y);
          // sprite1.move(0, -3);
     }
     // Down
     if ((cornerRadiusUpLeft >= (cornerRadius * 3 + bilateralRadius) && cornerRadiusUpLeft <= (cornerRadius * 3 + bilateralRadius * 2)) || (cornerRadiusUpRight >= (cornerRadius * 3 + bilateralRadius) && cornerRadiusUpRight <= (cornerRadius * 3 + bilateralRadius * 2)))
     {
          // cout << "down\n";
          sprite1.setPosition(sprite1.getPosition().x, sprite2.getPosition().y + sprite2.getTextureRect().height * sprite2.getScale().y);
          // sprite1.move(0, 3);
     }
}
