#include "Wraparound.hpp"  
	
Wraparound::Wraparound()
{
	
}
	
Wraparound::~Wraparound()
{
	
}


void Wraparound::MirorSide(sf::ConvexShape &shape)
{
     if (shape.getPosition().x < 0)
          shape.setPosition(1920, shape.getPosition().y);
     if (shape.getPosition().x > 1920)
          shape.setPosition(0, shape.getPosition().y);
     if (shape.getPosition().y < 0)
          shape.setPosition(shape.getPosition().x, 1080);
     if (shape.getPosition().y > 1080)
          shape.setPosition(shape.getPosition().x, 0);
}