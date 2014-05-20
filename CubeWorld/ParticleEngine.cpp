#include "Precompiled.h"

void CW::ParticleEngine::AddEmitter(ParticleEmitter* emitter)
{
	m_Emitters.push_back(emitter);
}

void CW::ParticleEngine::Update(float dt)
{
	for (ParticleEmitter* e : m_Emitters)
	{
		e->Update(dt);
	}
}

void CW::ParticleEngine::DrawAllParticles(Renderer* renderer)
{
	for (ParticleEmitter* e : m_Emitters)
	{
		e->Draw(renderer);
	}
}