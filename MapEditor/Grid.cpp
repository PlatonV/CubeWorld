#include "Grid.h"

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i< mLinePoints.size(); i+=2)
	{
		sf::Vertex line[] =
		{
			mLinePoints[i],
			mLinePoints[i+1]
		};

		line[0].color = sf::Color(245,245,245,180);
		line[1].color = sf::Color(245,245,245,180);

		target.draw(line, 2, sf::Lines);
	}
}