#ifndef FIRE_H
#define FIRE_H
#pragma once

#include <deque>

namespace CW
{
	class Renderer;
	class Vector2;

	class Fire
	{
	public:
		Vector2 Position;

		Fire(float x, float y);

		void Update(float dt);
		void Draw(Renderer* renderer);

		~Fire(void){}
	private:
		std::deque<Light*> mParticles;

		int t;
	};
}
#endif 
