#include "Precompiled.h"


void CW::Terrain::Init(void)
{
	PhysicsBody* b = new PhysicsBody();

	VerletPoint* V1 = new VerletPoint(0, 550);
	VerletPoint* V2 = new VerletPoint(60, 550);
	VerletPoint* V3 = new VerletPoint(60, 1000);
	VerletPoint* V4 = new VerletPoint(0, 1000);

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

	for (VerletPoint* p : b->Vertices)
	{
		p->IsStatic = true;
	}

	blocks.push_back(b);

	m_Engine->AddBody(b);

	for (int i=0;i<20;++i)
	{
		AddBlock();
	}
}

float CW::Terrain::GetHeight(float x)
{
	float h = 500;

	PhysicsBody* b = blocks[x/60];

	float dif = x - b->Vertices[0]->Position.x;

	float r = 60 / dif;

	float p = b->Vertices[0]->Position.y / b->Vertices[1]->Position.y;

	return b->Vertices[0]->Position.y + r * p - 50;
}

void CW::Terrain::Scroll(float value)
{
	if (blocks[blocks.size()-1]->Vertices[1]->Position.x < 1600)
	{
		AddBlock();
	}

	while (blocks[0]->Vertices[0]->Position.x < -60)
	{
		m_Engine->DeleteBody(blocks[0]);

		if (blocks.front())
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

void CW::Terrain::AddBlock(void)
{
	PhysicsBody* b = new PhysicsBody();

	int dif = rand() % 10;

	if (rand() % 10 < 4) dif *= -1;

	if (blocks[blocks.size() -1]->Vertices[1]->Position.y > 600) dif = -4;
	if (blocks[blocks.size() -1]->Vertices[1]->Position.y < 400) dif = 4;

	VerletPoint* V1 = new VerletPoint(blocks[blocks.size() -1]->Vertices[1]->Position.x,
		blocks[blocks.size() -1]->Vertices[1]->Position.y);
	VerletPoint* V2 = new VerletPoint(blocks[blocks.size() -1]->Vertices[1]->Position.x + 60,
		blocks[blocks.size() -1]->Vertices[1]->Position.y + dif);
	VerletPoint* V3 = new VerletPoint(blocks[blocks.size() -1]->Vertices[1]->Position.x + 60,
		1000);
	VerletPoint* V4 = new VerletPoint(blocks[blocks.size() -1]->Vertices[1]->Position.x,
		1000);

	b->AddVertex(V1);
	b->AddVertex(V2);
	b->AddVertex(V3);
	b->AddVertex(V4);

	b->AddEdge(V1, V2, true);

	for (VerletPoint* p : b->Vertices)
	{
		p->IsStatic = true;
	}

	blocks.push_back(b);

	m_Engine->AddBody(b);
}