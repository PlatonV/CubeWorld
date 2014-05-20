#ifndef PARTICLEEMITTERFACTORY_H
#define PARTICLEEMITTERFACTORY_H

namespace CW
{
	class Vector2;
	class Particle;
	class ParticleEmitter;

	class ParticleEmitterFactory
	{
	public:
		ParticleEmitterFactory(void) {}

		ParticleEmitter* CreateGlobalEmitter() const;
		ParticleEmitter* CreateExplosionEmitter(const Vector2& position, float magnitude) const;

		~ParticleEmitterFactory(void) {}
	};
}

#endif