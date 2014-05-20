#ifndef TERRAIN_H
#define TERRAIN_H
#pragma once

#include "Precompiled.h"

class TerrainBlock;

class Terrain
{
public:
	Terrain(void) {}

	void AddBlock(const Vector2& position);

	void Draw(sf::RenderWindow& window);

	std::string GetExportText();

	~Terrain(void) {}

private:
	std::vector<TerrainBlock*> m_Blocks;
};

#endif

