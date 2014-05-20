#include "Precompiled.h"

CW::Fire::Fire(float x, float y)
{
	Position = Vector2(x, y);
}

void CW::Fire::Update(float dt)
{
	/*
	* Spawn particles from time to time
	*/
	t++;
	if(t%5==0)
	{
		mParticles.push_back(new Light(
			Position.x,
			Position.y - 150,
			1, 1, 0,
			(float)(rand()%50000)));

	}

	/**
	* Update particles
	*/
	for (Light* l : mParticles)
	{
		l->Position += l->Velocity * 0.5f * dt;
		l->intensity/=1.02f;
        l->g -= 0.005f;
        l->b += 0.001f * dt;

		// Invert x-axis velocity from time to time
        int r = rand() % 100;
        r = r<98 ? r=1 : r=-1;
        l->Velocity.x *= r;
	}

	/**
	* Keep steady number
	*/
	if(mParticles.size()>40)
	{
		mParticles.pop_front();
	}
}

void CW::Fire::Draw(Renderer* renderer)
{
	for (Light* l : mParticles)
	{
		l->Draw(renderer);
	}
}
