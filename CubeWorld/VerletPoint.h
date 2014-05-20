#ifndef VERLETPOINT_H
#define VERLETPOINT_H
#pragma once

#include "Precompiled.h"

namespace CW
{
	class PhysicsBody;

	class VerletPoint 
	{
	public:
		Vector2 Position;
		Vector2 OldPosition;
		Vector2 Acceleration;

		PhysicsBody* Parent;

		float Friction;

		VerletPoint(float posX, float posY); 
		VerletPoint(PhysicsBody* parent, float posX, float posY); 
	};
}

#endif

