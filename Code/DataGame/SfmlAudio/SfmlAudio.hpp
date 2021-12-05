#ifndef SFMLAUDIO_H
#define SFMLAUDIO_H
#pragma once

#include <string>
#include <SFML/Audio.hpp>

class SfmlAudio
{
public:
	SfmlAudio();
	SfmlAudio(std::string scr);
	~SfmlAudio();

	void Play();
	void PlayLoop();
	void Stop();
	void SetVolume(int volume);

private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
};
#endif