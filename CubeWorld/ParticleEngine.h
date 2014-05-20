#ifndef PARTICLEENGINE_H
#define PARTICLEENGINE_H
#pragma once

#include <vector>

namespace CW
{
	class Renderer;
	class ParticleEmitter;

	class ParticleEngine
	{
	public:
		ParticleEngine(void) {}

		void AddEmitter(ParticleEmitter* emitter);

		void Update(float dt);
		void DrawAllParticles(Renderer* renderer);

		~ParticleEngine(void) {}

	private:
		std::vector<ParticleEmitter*> m_Emitters;
	};
}

#endif