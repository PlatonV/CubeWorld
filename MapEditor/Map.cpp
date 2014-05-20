#include "Map.h"

#include <fstream>

Map::Map(void)
{

}

void Map::AddTerrain(const Vector2& position)
{
	m_Terrain.AddBlock(position);
}

void Map::Draw(sf::RenderWindow& window)
{
	m_Terrain.Draw(window);
}

void Map::Export(char* filename)
{
	// EXPORT TERRAIN
	std::string terrainText = m_Terrain.GetExportText();

	std::ofstream f(filename);

	f<<terrainText;

	f.close();
}

Map::~Map(void)
{
}
