#ifndef SQUARE_H
#define SQUARE_H
#pragma once

#include <SFML\Graphics.hpp>
#include "SceneObject.h"

class Square : public sf::Drawable,  public SceneObject
{
public:
	Square(float size)
		: mSize(size)
	{ 
		isAffectedByGravity = false; 
	}

	void Init(void);

	~Square(void){}
private:
	sf::VertexArray	mPoints;
	float			mSize;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
        states.transform *= getTransform();

        // draw the vertex array
		target.draw(mPoints, states.transform);
	}
};

#endif