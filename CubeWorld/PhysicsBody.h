#ifndef PHYSICSBODY_H
#define PHYSYCSBODY_H
#pragma once

#define MAX_BODY_VERTICES 16
#define MAX_BODY_EDGES 8

namespace CW
{
	class Edge;

	class PhysicsBody 
	{
	public:
		Vector2 COM;

		BoundingBox BoundingBox;

		int VertexCount;
		int EdgeCount;

		std::vector<VerletPoint*>	Vertices;
		std::vector<Edge*>			Edges;

		PhysicsBody(void);
		PhysicsBody(std::vector<VerletPoint*> vertices);

		void AddVertex(VerletPoint* V);

		void ProjectToAxis(Vector2& Axis, float& Min, float& Max );
		void CalculateCenter();

		void StartCreation(void);
		void EndCreation(void);

		static PhysicsBody* CreateBox(float y, float x, float width, float height);
		static PhysicsBody* CreateBoulder(float y, float x, float width, float height);

	private:
		bool m_Creating;

		void AddEdge(VerletPoint* p1, VerletPoint* p2, bool collidable);
	};
}

#endif