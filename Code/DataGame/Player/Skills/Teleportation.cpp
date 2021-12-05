#include "Teleportation.hpp"
#include "../../Math/RandomNumber.hpp"

Teleportation::Teleportation()
{
    teleportationSound = new SfmlAudio("ressources/Sound/dragon-ball-z-teleportation-sound-effect.wav");
}

Teleportation::~Teleportation()
{
    delete teleportationSound;
}

void Teleportation::InstantTeleportation(sf::ConvexShape &shape)
{
    shape.setPosition(RandomNumber::RandomInt(0, 1920), RandomNumber::RandomInt(0, 1080));
    teleportationSound->Play();
}
