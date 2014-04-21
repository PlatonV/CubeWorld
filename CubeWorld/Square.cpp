#include "Square.h"


void Square::Init(void)
{
	sf::VertexArray quad(sf::Quads, 4);

	quad[0].position = sf::Vector2f(0,			0);
	quad[1].position = sf::Vector2f(mSize/2,	0);
	quad[2].position = sf::Vector2f(mSize/2,	mSize/2);
	quad[3].position = sf::Vector2f(0,			mSize/2);

	quad[0].color = sf::Color(50,50,50,255);
	quad[1].color = sf::Color(50,50,50,255);
	quad[2].color = sf::Color(50,50,50,255);
	quad[3].color = sf::Color(50,50,50,255);

	this->mPoints = quad;
}
