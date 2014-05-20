#ifndef GLOBALEMITTER_H
#define GLOBALEMITTER_H
#pragma once

#include <vector>
#include "ParticleEmitter.h"

namespace CW
{
	class Particle;
	class Renderer;

	class GlobalEmitter : public ParticleEmitter
	{
	public:
		GlobalEmitter(void) { Emitt(); }

		void Emitt(void);

		void Update(float dt);
		void Draw(Renderer* renderer) const;

		~GlobalEmitter(void);

	private:
		std::vector<Particle*> m_Particles;
	};
}

#endif