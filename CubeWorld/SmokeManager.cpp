#include "Precompiled.h"

#define MAXCOUNT 15

void CW::SmokeManager::CreateSmoke(float x, float y)
{
	if (mParticles.size() < MAXCOUNT)
	{
		mParticles.push_back(new SmokeParticle(
			x,
			y,
			1, 1, 1,
			(float)(10000)));
	}
}

void CW::SmokeManager::Scroll(float value)
{
	for (SmokeParticle* l : mParticles)
	{
		l->Position.x += value;
	}
}

void CW::SmokeManager::Update(float dt)
{
	mParticles.pop_back();

	/**
	* Update particles
	*/
	for (SmokeParticle* l : mParticles)
	{
		if(l->intensity < 500000)
			l->intensity*= 1.2f;
	}

	/**
	* Delete unnecesary
	*/
	for (int i=0;i<mParticles.size();++i)
	{
		if (mParticles[i]->Position.x < -100 || mParticles[i]->ttl > 10)
			mParticles.erase(mParticles.begin() + i);
	}
}

void CW::SmokeManager::Draw(Renderer* renderer)
{
	for (SmokeParticle* l : mParticles)
	{
		l->Draw(renderer);
	}
}
