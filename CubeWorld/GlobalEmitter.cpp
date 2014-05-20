#include "Precompiled.h"

void CW::GlobalEmitter::Emitt(void)
{
	for (int i=0; i<75; ++i)
	{
		Particle* p = new DustParticle(rand() % 2000, rand() % 900);

		m_Particles.push_back(p);
	}
}

void CW::GlobalEmitter::Update(float dt)
{
	for (Particle* p : m_Particles)
	{
		p->Update(dt);
	}
}

void CW::GlobalEmitter::Draw(Renderer* renderer) const
{
	for (Particle* p : m_Particles)
	{
		p->Draw(renderer);
	}
}