#include "SfmlAudio.hpp"

SfmlAudio::SfmlAudio()
{
}

SfmlAudio::SfmlAudio(std::string scr)
{
     buffer.loadFromFile(scr);
     sound.setBuffer(buffer);
}

SfmlAudio::~SfmlAudio()
{
}

void SfmlAudio::Play()
{
     sound.play();
}

void SfmlAudio::PlayLoop()
{
     sound.setLoop(true);
     sound.play();
}

void SfmlAudio::Stop()
{
     sound.stop();
}

void SfmlAudio::SetVolume(int volume)
{
     sound.setVolume(volume);
}
