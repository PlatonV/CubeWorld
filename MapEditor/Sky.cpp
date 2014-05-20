#include "Sky.h"


Sky::Sky(void)
{
	m_Vertices = sf::VertexArray(sf::Quads, 4);

	m_Vertices[0].position = sf::Vector2f(0, 0);
	m_Vertices[1].position = sf::Vector2f(WORLD_WIDTH, 0);
	m_Vertices[2].position = sf::Vector2f(WORLD_WIDTH, WORLD_HEIGHT);
	m_Vertices[3].position = sf::Vector2f(0, WORLD_HEIGHT);

	m_Vertices[0].color = sf::Color(25,25,200,255);
	m_Vertices[1].color = sf::Color(25,25,200,255);
	m_Vertices[2].color = sf::Color(180,180,255,255);
	m_Vertices[3].color = sf::Color(180,180,255,255);;
}

void Sky::Draw(sf::RenderWindow& window)
{
	window.draw(m_Vertices);
}

Sky::~Sky(void)
{
}
