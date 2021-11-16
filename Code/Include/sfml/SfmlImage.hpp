#ifndef SFMLIMAGE_H
#define SFMLIMAGE_H
#pragma once

#include <iostream>
#include "SfmlInclude.hpp"

using namespace std;

class SfmlImage
{
private:
public:
	SfmlImage();
	SfmlImage(string scr, int dimX, int dimY, double posX, double posY);
	~SfmlImage();

	Texture texture;
	Sprite sprite;

	void draw(sf::RenderWindow &window) const;
};
#endif