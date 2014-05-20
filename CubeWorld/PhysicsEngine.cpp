#include "Precompiled.h"

/*
* PUBLIC MEMBERS
*/

void CW::PhysicsEngine::AddBody(PhysicsBody* body)
{
	++BodyCount;
	m_Bodies.push_back(body);

	for (VerletPoint* p : body->Vertices)
	{
		AddVertex(p);
	}
	
	for (Edge* e : body->Edges)
	{
		AddEdge(e);
	}
}

void CW::PhysicsEngine::Update(void)
{
	UpdateForces();
	UpdateVerlet();
	Iterate();
}

void CW::PhysicsEngine::Draw(Renderer* renderer) 
{ 
	for (PhysicsBody* b : m_Bodies)
	{
		sf::ConvexShape convex;

		// resize it to 5 points
		convex.setPointCount(b->VertexCount);

		convex.setFillColor(sf::Color::Red);

		for (int i=0; i<b->VertexCount; ++i)
		{
			convex.setPoint(i, b->Vertices[i]->Position);
		}

		renderer->Draw(convex);

		for (Edge* e : b->Edges)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(e->P1->Position.x, e->P1->Position.y)),
				sf::Vertex(sf::Vector2f(e->P2->Position.x, e->P2->Position.y))
			};

			renderer->Draw(line, 2, sf::Lines);
		}
	}
}

/*
* PRIVATE MEMBERS
*/

void CW::PhysicsEngine::AddVertex(VerletPoint* p)
{
	++VertexCount;
	m_Vertices.push_back(p);
}

void CW::PhysicsEngine::AddEdge(Edge* e)
{
	++EdgeCount;
	m_Edges.push_back(e);
}

void CW::PhysicsEngine::UpdateForces(void)
{
	for (VerletPoint* p : m_Vertices)
	{
		p->Acceleration = Gravity;
	}
}

void CW::PhysicsEngine::UpdateVerlet(void) 
{ 
	for (VerletPoint* v : m_Vertices)
	{
		Vector2 Temp = v->Position;
		v->Position += v->Friction * v->Position - v->Friction * v->OldPosition + v->Acceleration * m_Timestep * m_Timestep;
		v->OldPosition = Temp;
		v->Friction = 1;
	}
}

void CW::PhysicsEngine::UpdateEdges() 
{
	for (Edge* e : m_Edges) 
	{
		// The vector between the two vertices
		Vector2 V1V2 = e->P2->Position - e->P1->Position; 

		// Current distance
		float V1V2Length = V1V2.Length(); 
		// Difference from the original length
		float Diff = V1V2Length - e->Length; 
		
		V1V2.Normalize();

		// Push both vertices apart by half of the difference to set both back to original length
		e->P1->Position += V1V2*Diff*0.5f;
		e->P2->Position -= V1V2*Diff*0.5f;
	}
}

float CW::PhysicsEngine::IntervalDistance(float MinA, float MaxA, float MinB, float MaxB) 
{
	if( MinA < MinB )
		return MinB - MaxA;
	else
		return MinA - MaxB;
}

bool CW::PhysicsEngine::DetectCollision(PhysicsBody* b1, PhysicsBody* b2) 
{
	float MinDistance = 10000.0f;
	for (Edge* e : m_Edges) 
	{
		if (!e->IsCollidable)
			continue;

		// Calculate the perpendicular to this edge and normalize it
		Vector2 Axis(e->P1->Position.y - e->P2->Position.y, e->P2->Position.x - e->P1->Position.x); 
		Axis.Normalize();

		// Project both bodies onto the perpendicular
		float MinA, MinB, MaxA, MaxB; 
		b1->ProjectToAxis( Axis, MinA, MaxA );
		b2->ProjectToAxis( Axis, MinB, MaxB );

		// Calculate the distance between the two intervals
		float Distance = IntervalDistance(MinA, MaxA, MinB, MaxB); 

		//If the intervals don't overlap, return, since there is no collision
		if(Distance > 0.0f) 
			return false;
		else if(abs(Distance) < MinDistance) 
		{
			MinDistance = abs(Distance);

			CollisionInfo.Normal = Axis; 
			CollisionInfo.E      = e;   // We found our edge
		}
	}

	CollisionInfo.Depth = MinDistance;

	// Make sure that the body containing the collision edge lies in B2 and the one conatining the collision vertex in B1
	if(CollisionInfo.E->Parent != b2) 
	{ 
		PhysicsBody* Temp = b2;
		b2 = b1;
		b1 = Temp;
	}

	// Make sure collision normal is pointing at b1
	int Sign = SGN(CollisionInfo.Normal*(b1->COM - b2->COM));
	
	//Remember that the line equation is N*( R - R0 ). We choose B2->Center as R0; the normal N is given by the collision normal

	if(Sign != 1)
		CollisionInfo.Normal = -CollisionInfo.Normal; //Revert the collision normal if it points away from B1

	Vector2 CollisionVector = CollisionInfo.Normal*CollisionInfo.Depth;

	//Initialize the smallest distance to a large value
	float SmallestD = 10000.0f; 
	for (VerletPoint* p : b1->Vertices) 
	{
		float Distance = CollisionInfo.Normal*(p->Position - b2->COM);

		if( Distance < SmallestD ) 
		{ 
			SmallestD = Distance;
			CollisionInfo.V = p;
		}
	}

	//There is no separating axis. Report a collision!
	return true; 
}

void CW::PhysicsEngine::ProcessCollision(void)
{
	VerletPoint* p1 = CollisionInfo.E->P1;
	VerletPoint* p2 = CollisionInfo.E->P2;

	p1->Friction = 0.9f;
	p2->Friction = 0.9f;

	Vector2 CollisionVector = CollisionInfo.Normal*CollisionInfo.Depth;

	float T;
	if( std::abs( p1->Position.x - p2->Position.x ) > std::abs( p1->Position.y - p2->Position.y ) )
		T = ( CollisionInfo.V->Position.x - CollisionVector.x - p1->Position.x )/(  p2->Position.x - p1->Position.x );
	else
		T = ( CollisionInfo.V->Position.y - CollisionVector.y - p1->Position.y )/(  p2->Position.y - p1->Position.y );

	float Lambda = 1.0f/( T*T + ( 1 - T )*( 1 - T ) );

	p1->Position -= CollisionVector*( 1 - T )*0.5f*Lambda;
	p2->Position -= CollisionVector*      T  *0.5f*Lambda;
	
	CollisionInfo.V->Position += CollisionVector*0.5f;
}

void CW::PhysicsEngine::Iterate(void)
{
	for(int i = 0; i < m_Iterations; ++i) 
	{
		// Keep the vertices in the screen
		for (VerletPoint* p : m_Vertices) 
		{
			if (p->Position.y > 600)
			{
				p->Position.y = 600;
				p->Friction = 0.9f;
			}
			if (p->Position.x > 800)
			{
				p->Position.x = 800;
				p->Friction = 0.9f;
			}
			if (p->Position.x < 0)
			{
				p->Position.x = 0;
				p->Friction = 0.9f;
			}
		}

		// Apply edge constraints
		UpdateEdges();

		for (PhysicsBody* b : m_Bodies)
		{
			b->CalculateCenter();
		}

		for (PhysicsBody* b1 : m_Bodies) 
		{ 
			for(PhysicsBody* b2 : m_Bodies) 
			{
				if(b1 != b2)
				{
					if (BoundingBox::CheckIntersection(&(b1->BoundingBox), &(b2->BoundingBox)))
					{
						if (DetectCollision(b1, b2))
						{
							// Process collision info with CollisionInfo data
							ProcessCollision();
						}
					}
				}
			}
		}
	}
}
