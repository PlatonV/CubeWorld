#include "Precompiled.h"

CW::DustParticle::DustParticle(float x, float y)
{
	this->Position.x = x;
	this->Position.y = y;

	Destination.x = rand() % 2000;
	Destination.y = rand() % 800;
}

void CW::DustParticle::Update(float dt)
{
	Vector2 v;

	v = (Destination - Position);
	v.Normalize();

	this->Position += v * (rand() % 10) / 300;
}

void CW::DustParticle::Draw(Renderer* renderer)
{
	sf::Vertex* v = new sf::Vertex(Position);

	v->color == sf::Color::White;

	renderer->Draw(v, 1, sf::Points);
}