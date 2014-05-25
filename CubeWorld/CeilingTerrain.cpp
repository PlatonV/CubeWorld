#include "Precompiled.h"


void CW::CeilingTerrain::Init(void)
{
	PhysicsBody* b = new PhysicsBody();

	VerletPoint* V1 = new VerletPoint(0, 0);
	VerletPoint* V2 = new VerletPoint(60, 0);
	VerletPoint* V3 = new VerletPoint(60, 100);
	VerletPoint* V4 = new VerletPoint(0, 100);

	b->AddVertex(V1);
	b->AddVertex(V2);
	b->AddVertex(V3);
	b->AddVertex(V4);

	for (VerletPoint* p : b->Vertices)
	{
		p->IsStatic = true;
	}

	blocks.push_back(b);

	for (int i=0;i<20;++i)
	{
		AddBlock();
	}
}

void CW::CeilingTerrain::Scroll(float value)
{
	if (blocks[blocks.size()-1]->Vertices[1]->Position.x < 1600)
	{
		AddBlock();
	}

	while (blocks[0]->Vertices[0]->Position.x < -60)
	{
		blocks.pop_front();
	}

	for (PhysicsBody* b : blocks)
	{
		for (VerletPoint* p : b->Vertices)
		{
			p->Position.x += value;
		}
	}
}

void CW::CeilingTerrain::Draw(Renderer* renderer)
{
	glDisable(GL_BLEND);

	for (PhysicsBody* b : blocks)
	{
		sf::ConvexShape convex;

		// resize it to 5 points
		convex.setPointCount(b->VertexCount);

		convex.setFillColor(sf::Color::Black);

		for (int i=0; i<b->VertexCount; ++i)
		{
			convex.setPoint(i, b->Vertices[i]->Position);
		}

		renderer->Draw(convex);
	}

	glEnable(GL_BLEND);
}

void CW::CeilingTerrain::AddBlock(void)
{
	PhysicsBody* b = new PhysicsBody();

	int dif = rand() % 10;

	if (rand() % 10 < 4) dif *= -1;

	if (blocks[blocks.size() -1]->Vertices[2]->Position.y > 200) dif = -4;
	if (blocks[blocks.size() -1]->Vertices[2]->Position.y < 50) dif = 4;

	VerletPoint* V1 = new VerletPoint(blocks[blocks.size() -1]->Vertices[1]->Position.x,
		0);
	VerletPoint* V2 = new VerletPoint(blocks[blocks.size() -1]->Vertices[1]->Position.x + 60,
		0);
	VerletPoint* V3 = new VerletPoint(blocks[blocks.size() -1]->Vertices[1]->Position.x + 60,
		blocks[blocks.size() -1]->Vertices[2]->Position.y + dif);
	VerletPoint* V4 = new VerletPoint(blocks[blocks.size() -1]->Vertices[1]->Position.x,
		blocks[blocks.size() -1]->Vertices[2]->Position.y);

	b->AddVertex(V1);
	b->AddVertex(V2);
	b->AddVertex(V3);
	b->AddVertex(V4);

	blocks.push_back(b);
}