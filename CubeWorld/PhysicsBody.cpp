#include "Precompiled.h"

/*
* PUBLIC MEMBERS
*/

CW::PhysicsBody::PhysicsBody() 
{
	VertexCount	=	0;
	EdgeCount	=	0;
	m_Creating	=	0;
}

CW::PhysicsBody::PhysicsBody(std::vector<VerletPoint*> vertices) 
{
	VertexCount	=	0;
	EdgeCount	=	0;
	m_Creating	=	0;
	Vertices	=	vertices;
}

void CW::PhysicsBody::AddVertex(VerletPoint *v) 
{
//	if(m_Creating)
	{
		Vertices.push_back(v);
		++VertexCount;
	}
}

void CW::PhysicsBody::ProjectToAxis(Vector2& Axis, float& Min, float& Max ) 
{
	float DotP = Axis * Vertices[0]->Position;

	Min = Max = DotP; //Set the minimum and maximum values to the projection of the first vertex

	for( int I = 0; I < VertexCount; I++ ) {
		DotP = Axis * Vertices[ I ]->Position; //Project the rest of the vertices onto the axis and extend the interval to the left/right if necessary

		Min = std::min( DotP, Min );
		Max = std::max( DotP, Max );
	}
}

void CW::PhysicsBody::CalculateCenter() 
{
	COM = Vector2(0.0f, 0.0f);

	BoundingBox.MinX = 10000;
	BoundingBox.MinY = 10000;
	BoundingBox.MaxX = -10000;
	BoundingBox.MaxY = -10000;

	for(VerletPoint* v : Vertices)
	{
		COM += v->Position;

		BoundingBox.MinX = MIN(BoundingBox.MinX, v->Position.x);
		BoundingBox.MinY = MIN(BoundingBox.MinY, v->Position.y);
		BoundingBox.MaxX = MAX(BoundingBox.MaxX, v->Position.x);
		BoundingBox.MaxY = MAX(BoundingBox.MaxY, v->Position.y);
	}

	COM /= VertexCount;
}

CW::PhysicsBody* CW::PhysicsBody::CreateBox(float x, float y, float width, float height) 
{
	PhysicsBody* b = new PhysicsBody();

	VerletPoint* V1 = new VerletPoint(x + rand() % 10, y + rand() % 10);
	VerletPoint* V2 = new VerletPoint(x+50 + rand() % 10, y + rand() % 10);
	VerletPoint* V3 = new VerletPoint(x+50 + rand() % 10, y+50 + rand() % 10);
	VerletPoint* V4 = new VerletPoint(x + rand() % 10, y+50 + rand() % 10);

	b->AddVertex(V1);
	b->AddVertex(V2);
	b->AddVertex(V3);
	b->AddVertex(V4);

	b->AddEdge(V1, V2, true);
	b->AddEdge(V2, V3, true);
	b->AddEdge(V3, V4, true);
	b->AddEdge(V4, V1, true);

	b->AddEdge(V1, V3, false);
	b->AddEdge(V2, V4, false);

	return b;
}

CW::PhysicsBody* CW::PhysicsBody::CreateBoulder(float x, float y, float width, float height) 
{
	PhysicsBody* b = new PhysicsBody();

	VerletPoint* V1 = new VerletPoint(x, y);
	VerletPoint* V2 = new VerletPoint(x+50, y);
	VerletPoint* V3 = new VerletPoint(x+50, y+50);
	VerletPoint* V4 = new VerletPoint(x, y+50);

	b->AddVertex(V1);
	b->AddVertex(V2);
	b->AddVertex(V3);
	b->AddVertex(V4);

	b->AddEdge(V1, V2, true);
	b->AddEdge(V2, V3, true);
	b->AddEdge(V3, V4, true);
	b->AddEdge(V4, V1, true);

	b->AddEdge(V1, V3, false);
	b->AddEdge(V2, V4, false);

	return b;
}

void CW::PhysicsBody::StartCreation(void)
{
	m_Creating = true;
}

void CW::PhysicsBody::EndCreation(void)
{
	m_Creating = false;
	
	VerletPoint* prev = nullptr;

	for (VerletPoint* v : Vertices)
	{
		v->Parent = this;

		if (prev != nullptr)
		{
			AddEdge(prev, v, true);
		}

		prev = v;
	}

	if (prev && Vertices[0])
	{
		AddEdge(prev, Vertices[0], true);
	}
}

/*
* PRIVATE MEMBERS
*/

void CW::PhysicsBody::AddEdge(VerletPoint* p1, VerletPoint* p2, bool collidable)
{
	Edges.push_back(new Edge(p1, p2, collidable));
}