#ifndef SFMLAUDIO_H
#define SFMLAUDIO_H
#pragma once

#include <iostream>
#include "SfmlInclude.hpp"

using namespace std;

class SfmlAudio
{
private:
public:
	SfmlAudio();
	SfmlAudio(string scr);
	~SfmlAudio();

	sf::SoundBuffer buffer;
	sf::Sound sound;
};
#endif