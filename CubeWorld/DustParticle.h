#ifndef DUSTPARTICLE_H
#define DUSTPARTICLE_H
#pragma once

namespace CW
{
	class Renderer;
	class Particle;
	class Vector2;

	class DustParticle : public Particle
	{
	public:
		Vector2 Destination;

		DustParticle(float x, float y);

		void Update(float dt);
		void Draw(Renderer* renderer);

		~DustParticle(void) {}
	};
}

#endif