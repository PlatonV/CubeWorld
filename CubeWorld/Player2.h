#ifndef PLAYER2_H
#define PLAYER2_H
#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

namespace CW
{
	class Renderer;
	class Terrain;
	class PhysicsBody;

	class Player2
	{
	public:
		PhysicsBody* body;
		sf::Vector2f	Position;
		sf::Vector2f	Velocity;

		Player2(float x, float y, Terrain* terrain);
		void Init(void);

		void MoveRight(void);
		void MoveLeft(void);
		void MoveDown(void);
		void Jump(void);

		void GetHit(PhysicsBody* body);

		void Update(float dt);
		void Draw(Renderer* renderer);

		~Player2(void){}

	private:	
		Terrain* terrain;

		bool			mOnGround;
	};
}

#endif