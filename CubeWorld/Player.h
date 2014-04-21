#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include <SFML\Graphics.hpp>
#include "SceneObject.h"

class Player : public sf::Drawable,  public SceneObject
{
public:
	Player(void) { isAffectedByGravity = true; }
	void Init(void);

	void MoveRight(void);
	void MoveLeft(void);
	void Jump(void);

	~Player(void){}

private:
	sf::VertexArray	mPoints;
	sf::Vector2f	Velocity;

	float			mSize;
	bool			mOnGround;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
        states.transform *= getTransform();

        // draw the vertex array
		target.draw(mPoints, states.transform);
	}
};

#endif