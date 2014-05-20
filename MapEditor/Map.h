#ifndef MAP_H
#define MAP_H
#pragma once

#include "Precompiled.h"

class Map
{
public:
	Map(void);

	void AddTerrain(const Vector2& position);

	void Draw(sf::RenderWindow& window);

	void Export(char* filename);

	~Map(void);
private:
	Terrain m_Terrain;
};

#endif
