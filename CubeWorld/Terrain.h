#ifndef TERRAIN_H
#define TERRAIN_H
#pragma once

#include <deque>

namespace CW
{
	class PhysicsEngine;

	class Terrain
	{
	public:
		Terrain() {}

		Terrain(PhysicsEngine* engine) 
		{ 
			m_Engine = engine;
			Init(); 
		}

		void Init(void);

		float GetHeight(float x);

		void Scroll(float value);

		std::deque<PhysicsBody*> blocks;

		~Terrain(void) {}
	private:
		PhysicsEngine* m_Engine;

		void AddBlock(void);
	};
}

#endif

