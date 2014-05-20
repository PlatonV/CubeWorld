#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H
#pragma once

#include <vector>

namespace CW
{
	class Particle;
	class Renderer;

	class ParticleEmitter
	{
	public:
		enum EmitterType
		{
			Explosion,
			Global
		}Type;

		ParticleEmitter(void);

		virtual void Emitt() {}
		virtual void Update(float dt) {}
		virtual void Draw(Renderer* renderer) const;

		~ParticleEmitter(void);

	private:
		std::vector<Particle*> m_Particles;
	};
}

#endif