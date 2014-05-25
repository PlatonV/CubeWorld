#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#pragma once

#include "VerletPoint.h"
#include "Edge.h"
#include "PhysicsBody.h"

#define MAX_BODIES 50

namespace CW
{
	class Vector2;
	class Renderer;
	class SmokeManager;

	class PhysicsEngine 
	{
	public:
		//EXTRA SMOKE
		SmokeManager* sm;

		int		VertexCount;
		int		EdgeCount;
		int		BodyCount;

		void Scroll(float value);

		bool DetectCollision(PhysicsBody* b1, PhysicsBody*b2);

		void Update(void);
		void Draw(Renderer* renderer);

		void AddBody(PhysicsBody* body);
		void DeleteBody(PhysicsBody* body);

		PhysicsEngine() :
			Gravity(Vector2(0,0.3f)),
			VertexCount(0),
			EdgeCount(0),
			BodyCount(0),
			m_Iterations(5),
			m_Timestep(0.8f)
		{}
	private:
		// FORCES
		Vector2 Gravity;

		// ENTITIES
		std::vector<VerletPoint*> m_Vertices;
		std::vector<Edge*> m_Edges;
		std::vector<PhysicsBody*> m_Bodies;

		// UTILITY
		float	m_Timestep;
		int		m_Iterations;

		void AddVertex(VerletPoint* p);
		void AddEdge(Edge* e);

		void UpdateForces(void);
		void UpdateVerlet(void);
		void UpdateEdges(void);
		void Iterate(void);

		float IntervalDistance(float MinA, float MaxA, float MinB, float MaxB);

		void ProcessCollision(void);

		// COLLISION MANIFOLD
		struct 
		{
			float				Depth;
			Vector2  Normal;

			Edge*			E;
			VerletPoint*	V;
		} CollisionInfo;
	};
}


#endif