#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

namespace CW
{
	class Renderer;
	class Terrain;
	class PhysicsBody;

	class Player
	{
	public:
		PhysicsBody* body;
		sf::Vector2f	Velocity;
		sf::Vector2f	Position;

		Player(float x, float y, Terrain* terrain);
		void Init(void);

		void MoveRight(void);
		void MoveLeft(void);
		void MoveDown(void);
		void Jump(void);

		void GetHit(PhysicsBody* body);

		void Update(float dt);
		void Draw(Renderer* renderer);

		~Player(void){}

		int Lives;
	private:	
		Terrain* terrain;

		bool			mOnGround;
	};
}

#endif