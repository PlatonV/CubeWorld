#ifndef FIRE_H
#define FIRE_H
#pragma once

#include "Light.h"
#include "SceneObject.h"
#include <deque>

class Fire : public SceneObject
{
public:
	std::deque<Light> mParticles;

    Fire(float x, float y)
    {
		this->setPosition(x,y);
    }

    void Update(sf::Time dt);
	~Fire(void){}
private:
	std::deque<Light>::iterator partIT;

    int t;
};
#endif 
