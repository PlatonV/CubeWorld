#ifndef CEILINGTERRAIN_H
#define CEILINGTERRAIN_H
#pragma once

#include <deque>

namespace CW
{
	class PhysicsBody;
	class PhysicsEngine;
	class Renderer;

	class CeilingTerrain
	{
	public:
		std::deque<PhysicsBody*> blocks;

		CeilingTerrain() 
		{ 
			Init(); 
		}

		void Init(void);

		void Scroll(float value);

		void Draw(Renderer* renderer);

		~CeilingTerrain(void) {}
	private:
		PhysicsEngine* m_Engine;

		void AddBlock(void);
	};
}

#endif