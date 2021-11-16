#ifndef SKILLS_H
#define SKILLS_H
#pragma once

#include "../../Include/MainInclude.hpp"
#include "./Laser.hpp"

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