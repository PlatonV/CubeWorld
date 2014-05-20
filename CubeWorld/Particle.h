#ifndef PARTICLE_H
#define PARTICLE_H

namespace CW
{
	class Vector2;
	class Renderer;

	class Particle
	{
	public:
		enum ParticleType
		{
			Dot,
			Sprite
		}Type;

		Vector2 Position;

		Particle(void) {}

		virtual void Update(float dt) {}
		virtual void Draw(Renderer* renderer) {}

		~Particle(void) {}
	};
}

#endif