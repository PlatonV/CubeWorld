#include "TerrainBlock.h"


TerrainBlock::TerrainBlock(const Vector2& position)
{
	m_Vertices = sf::VertexArray(sf::Quads, 4);

	m_Vertices[0].position = sf::Vector2f(position.x, position.y);
	m_Vertices[1].position = sf::Vector2f(position.x + 50, position.y);
	m_Vertices[2].position = sf::Vector2f(position.x + 50, position.y + 50);
	m_Vertices[3].position = sf::Vector2f(position.x,  position.y + 50);

	m_Vertices[0].color = sf::Color(0,0,0,255);
	m_Vertices[1].color = sf::Color(0,0,0,255);
	m_Vertices[2].color = sf::Color(0,0,0,255);
	m_Vertices[3].color = sf::Color(0,0,0,255);
}

void TerrainBlock::Draw(sf::RenderWindow& window)
{
	window.draw(m_Vertices);
}

Vector2 TerrainBlock::GetPosition() const
{
	return Vector2(m_Vertices[0].position.x, m_Vertices[0].position.y);
}

TerrainBlock::~TerrainBlock(void)
{
}
