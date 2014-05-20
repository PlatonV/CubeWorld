#ifndef TERRAINBLOCK_H
#define TERRAINBLOCK_H
#pragma once

#include "Precompiled.h"

class TerrainBlock
{
public:
	TerrainBlock(void);
	TerrainBlock(const Vector2& position);

	void Draw(sf::RenderWindow& window);

	Vector2 GetPosition() const;

	~TerrainBlock(void);

private:
	sf::VertexArray m_Vertices;
};

#endif
