#include "VerletPoint.h"

CW::VerletPoint::VerletPoint(float PosX, float PosY) 
{
	Position    = Vector2( PosX, PosY );
	OldPosition = Vector2( PosX, PosY );

	Friction = 1;
}

CW::VerletPoint::VerletPoint(PhysicsBody* Body, float PosX, float PosY) 
{
	VerletPoint(PosX, PosY);

	Parent = Body;
}