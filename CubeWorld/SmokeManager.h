#ifndef SMOKEMANAGER_H
#define SMOKEMANAGER_H
#pragma once

#include <deque>

namespace CW
{
	class Renderer;
	class Vector2;
	class SmokeParticle;

	class SmokeManager
	{
	public:
		SmokeManager() { t = 0; }

		void CreateSmoke(float x, float y);

		void Scroll(float value);

		void Update(float dt);
		void Draw(Renderer* renderer);

		~SmokeManager(void){}
	private:
		std::deque<SmokeParticle*> mParticles;

		int t;
	};
}
#endif 
