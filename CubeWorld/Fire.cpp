#include "Fire.h"


void Fire::Update(sf::Time dt)
{
	/*
	* Spawn particles from time to time
	*/
	t++;
	if(t%5==0)
	{
		mParticles.push_back(Light(
			this->getPosition().x, 
			this->getPosition().y,
			1, 1, 0,
			(float)(rand()%50000)));

	}

	/**
	* Update particles
	*/
	for (partIT = mParticles.begin(); partIT != mParticles.end(); ++partIT)
	{
		(*partIT).Position += (*partIT).Velocity * 0.5f * dt.asSeconds();
		(*partIT).intensity/=1.02f;
        (*partIT).g -= 0.005f;
        (*partIT).b += 0.001f * dt.asSeconds();

		// Invert x-axis velocity from time to time
        int r = rand() % 100;
        r = r<98 ? r=1 : r=-1;
        (*partIT).Velocity.x *= r;
	}

	/**
	* Keep steady number
	*/
	if(mParticles.size()>40)
	{
		mParticles.pop_front();
	}

}
