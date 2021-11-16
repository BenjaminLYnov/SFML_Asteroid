#include "SfmlImage.hpp"

SfmlImage::SfmlImage()
{
}

SfmlImage::SfmlImage(string scr, int dimX, int dimY, double posX, double posY)
{
     texture.loadFromFile(scr, sf::IntRect(0, 0, dimX, dimY));
     sprite.setTexture(texture);
     sprite.setPosition(posX, posY);
}

SfmlImage::~SfmlImage()
{
}

void SfmlImage::draw(sf::RenderWindow &window) const
{
     window.draw(sprite);
}

