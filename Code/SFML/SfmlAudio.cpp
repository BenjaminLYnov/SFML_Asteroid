#include "SfmlAudio.hpp"  
	
SfmlAudio::SfmlAudio()
{
	
}

SfmlAudio::SfmlAudio(string scr)
{
     buffer.loadFromFile(scr);
     sound.setBuffer(buffer);
}
	
SfmlAudio::~SfmlAudio()
{
	
}
