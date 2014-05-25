#ifndef SMOKEPARTICLE_H
#define SMOKEPARTICLE_H
#pragma once

namespace CW
{
	class Renderer;
	class Vector2;

	class SmokeParticle
	{
	public:
		int ttl;
		Vector2 Position;
		float r;
		float g;
		float b;
		float intensity;
		Vector2 Velocity;

		SmokeParticle() {}
		SmokeParticle(float _x, float _y, float _r, float _g, float _b, float inten);

		void Draw(Renderer* renderer);

		~SmokeParticle(void) {}
	};
}

#endif
