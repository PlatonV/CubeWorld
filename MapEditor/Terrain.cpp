#include "Precompiled.h"

void Terrain::AddBlock(const Vector2& position)
{
	// The new snapped to grid position
	Vector2* p = new Vector2(((int)position.x/50)*50, ((int)position.y/50)*50);

	// Does a block on the same position already exist?
	bool exists = false;

	// Search for a block on the same position
	for (TerrainBlock* b : m_Blocks)
	{
		if (b->GetPosition().x == p->x  && b->GetPosition().y == p->y) {
			exists = true;
		}
	}

	// Add the new block
	if (!exists) {
		m_Blocks.push_back(new TerrainBlock(*p));
	}

	delete p;
}

void Terrain::Draw(sf::RenderWindow& window)
{
	for (TerrainBlock* block : m_Blocks)
	{
		block->Draw(window);
	}
}

std::string Terrain::GetExportText()
{
	std::string s;

	for (TerrainBlock* b : m_Blocks)
	{
		s.append(std::to_string((int)b->GetPosition().x));
		s.append(" ");
		s.append(std::to_string((int)b->GetPosition().y));
		s.append(" ");
	}

	return s;
}