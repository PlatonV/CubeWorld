#ifndef EDGE_H
#define EDGE_H
#pragma once

class VerletPoint;
class PhysicsBody;

namespace CW
{
	class Edge
	{
	public:
		VerletPoint* P1;
		VerletPoint* P2;

		float Length;
		bool IsCollidable;

		PhysicsBody* Parent;

		Edge(VerletPoint* v1, VerletPoint* v2, bool isCollidable);
		Edge(PhysicsBody* Body, VerletPoint* v1, VerletPoint* v2, bool isCollidable);

		~Edge(void);
	};
}

#endif

