#ifndef LIGHT_H
#define LIGHT_H
#pragma once

#include "SceneObject.h"

class Light
{
public:
	sf::Vector2f Position;
    float r;
    float g;
    float b;
    float intensity;
	sf::Vector2f Velocity;

    Light(float _x, float _y, float _r, float _g, float _b, float inten)
    {
        r=_r;
        g=_g;
        b=_b;

        intensity = inten;

		Position.x = _x;
		Position.y = _y;

		Velocity.x = (float)(rand() % 4);
        Velocity.x *= 10;

        int r = rand() % 10;
        r = r<5 ? r=1 : r=-1;
        Velocity.x *= r;

        Velocity.y = (float)(-rand() % 12 - 4);
        Velocity.y *= 10;
    }

	~Light(void) {}
};

#endif
