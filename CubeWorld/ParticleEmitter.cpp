#include "Precompiled.h"


CW::ParticleEmitter::ParticleEmitter(void)
{
}

void CW::ParticleEmitter::Draw(Renderer* renderer) const
{
	for (Particle* p : m_Particles)
	{
		p->Draw(renderer);
	}
}

CW::ParticleEmitter::~ParticleEmitter(void)
{
}
