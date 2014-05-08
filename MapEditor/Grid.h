#ifndef GRID_H
#define GRID_H

#pragma once

#include "SFML\Graphics.hpp"
#include "SFML\OpenGL.hpp"
#include <vector>

class Grid : public sf::Drawable
{
public:

	Grid(float size)
		: mCellSize(size)
	{
		for (unsigned int i = mCellSize; i < 10000; i+=mCellSize)
		{
			sf::Vertex v1 = sf::Vertex(sf::Vector2f(i, 0));
			sf::Vertex v2 = sf::Vertex(sf::Vector2f(i, 2000));

			mLinePoints.push_back(v1);
			mLinePoints.push_back(v2);
		}

		for (unsigned int i = mCellSize; i < 2000; i+=mCellSize)
		{
			sf::Vertex v1 = sf::Vertex(sf::Vector2f(0, i));
			sf::Vertex v2 = sf::Vertex(sf::Vector2f(10000 * mCellSize, i));

			mLinePoints.push_back(v1);
			mLinePoints.push_back(v2);
		}
	}

private:
	float	mCellSize;

	std::vector<sf::Vertex> mLinePoints;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif