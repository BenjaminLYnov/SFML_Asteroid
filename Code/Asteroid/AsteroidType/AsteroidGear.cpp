#include "AsteroidGear.hpp"

AsteroidGear::AsteroidGear()
{
	direction = Vector2f(RandomNumber::RandomFloat(-1, 1), RandomNumber::RandomFloat(-1, 1));
	direction = Vector2D::Normalized(direction);
	lifeTime.start();
}

AsteroidGear::~AsteroidGear()
{
}

void AsteroidGear::Move()
{
	asteroidShape.shape.move(direction * speedMove);
}

void AsteroidGear::Update()
{
	lifeTime.upTime();
	Move();
}

void AsteroidGear::Draw(RenderWindow &window) const
{
	asteroidShape.draw(window);
}