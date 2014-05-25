#include "Precompiled.h"

CW::VerletPoint::VerletPoint(float PosX, float PosY, bool isStatic) 
{
	Position    = Vector2( PosX, PosY );
	OldPosition = Vector2( PosX, PosY );

	IsStatic = isStatic;
	Friction = 1;
}

CW::VerletPoint::VerletPoint(PhysicsBody* parent, float PosX, float PosY, bool isStatic) 
{
	VerletPoint(PosX, PosY);

	Parent = parent;
}