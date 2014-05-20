#include "Precompiled.h"

CW::ParticleEmitter* CW::ParticleEmitterFactory::CreateGlobalEmitter()const
{
	GlobalEmitter* gemitter = new GlobalEmitter();

	return gemitter;
}

CW::ParticleEmitter* CW::ParticleEmitterFactory::CreateExplosionEmitter(const Vector2& position, float magnitude) const
{
	ParticleEmitter* emitter = new ParticleEmitter();

	return emitter;
}