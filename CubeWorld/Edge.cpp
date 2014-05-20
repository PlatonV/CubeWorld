#include "Precompiled.h"

CW::Edge::Edge(VerletPoint* v1, VerletPoint* v2, bool isCollidable) 
{
	P1 = v1;
	P2 = v2;

	IsCollidable = isCollidable;

	Length   = (v2->Position - v1->Position ).Length();
}

CW::Edge::Edge(PhysicsBody* Body, VerletPoint* v1, VerletPoint* v2, bool isCollidable) 
{
	Edge(v1, v2, isCollidable);

	Parent = Body;
}

CW::Edge::~Edge(void)
{
}
