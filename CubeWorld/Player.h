#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include "Precompiled.h"

namespace CW
{
	class Player
	{
	public:
		Player(void) {}
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
	};
}

#endif