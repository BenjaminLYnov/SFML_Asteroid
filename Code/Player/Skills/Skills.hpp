#ifndef SKILLS_H
#define SKILLS_H
#pragma once

#include "./Laser.hpp"
#include "../../SFML/SfmlImage.hpp"
#include "../../SFML/SfmlAudio.hpp"

using namespace sf;

class Skills
{
private:
	bool keyJ;

public:
	Skills();
	~Skills();

	vector<Laser> lasers;

	void input(Event &event);
	void Update();
	void draw(RenderWindow &window) const;
};
#endif