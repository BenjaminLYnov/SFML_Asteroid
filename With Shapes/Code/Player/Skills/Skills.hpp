#ifndef SKILLS_H
#define SKILLS_H
#pragma once

#include "./Laser.hpp"
#include "../../SFML/SfmlAudio.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Skills
{
private:
    bool keySpace;

public:
	Skills();
	~Skills();

	vector<Laser> lasers;

	void input(Event &event);
	void Update();
	void draw(RenderWindow &window) const;
};
#endif
