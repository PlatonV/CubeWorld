#include "Precompiled.h"

CW::Player::Player(float x, float y, Terrain* terrain)
{
	Position.x = x;
	Position.y = y;

	this->terrain = terrain;

	Init();
}

void CW::Player::Init(void)
{
	VerletPoint* V1 = new VerletPoint(Position.x, Position.y);
	VerletPoint* V2 = new VerletPoint(Position.x+50, Position.y);
	VerletPoint* V3 = new VerletPoint(Position.x+50, Position.y+50);
	VerletPoint* V4 = new VerletPoint(Position.x, Position.y+50);

	body = new PhysicsBody();

	body->AddVertex(V1);
	body->AddVertex(V2);
	body->AddVertex(V3);
	body->AddVertex(V4);

	body->AddEdge(V1, V2, true);
	body->AddEdge(V2, V3, true);
	body->AddEdge(V3, V4, true);
	body->AddEdge(V4, V1, true);

	Lives = 3;
}

void CW::Player::MoveRight(void)
{
	if (mOnGround)
	{
		if (Velocity.x < 20 && Position.x < 1500)
			Velocity.x++;
	}
	else
	{
		Velocity.x += 0.5f;
	}
}

void CW::Player::MoveLeft(void)
{
	if (mOnGround)
	{
		if (Velocity.x > -20 && Position.x > 10)
			Velocity.x--;
	}
	else
	{
		Velocity.x -= 0.5f;
	}
}

void CW::Player::Jump(void)
{
	if (mOnGround)
	{
		Velocity.y-=10;
		mOnGround = false;
	}
}

void CW::Player::Update(float dt)
{
	float groundY = terrain->GetHeight(Position.x);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		MoveRight();
	}
	else
	{
		if (Velocity.x > 0)
		{
			Velocity.x /=1.5f;
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		MoveLeft();
	}
	else
	{
		if (Velocity.x < 0)
		{
			Velocity.x /=1.5f;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (!mOnGround)
		{
			Velocity.y -= 0.3f;
		}
	}

	Velocity.y += 0.5f;

	Position += Velocity;

	if (Position.y > groundY)
	{
		Position.y = groundY;
		mOnGround = true;
		Velocity.y = 0;
	}

	if (Position.x > 1200)
	{
		Position.x = 1200;
		Velocity.x = 0;
	}

	if (Position.x < 10)
	{
		Position.x = 10;
		Velocity.x = 0;
	}

	body->Vertices[0]->Position = Vector2(Position.x + Velocity.x,			Position.y - Velocity.y);
	body->Vertices[1]->Position = Vector2(Position.x + 50 + Velocity.x,	Position.y + Velocity.y);
	body->Vertices[2]->Position = Vector2(Position.x + 50 + Velocity.x,	Position.y + 50 + Velocity.y);
	body->Vertices[3]->Position = Vector2(Position.x + Velocity.x,			Position.y + 50 - Velocity.y);

	body->CalculateCenter();
}

void CW::Player::Draw(Renderer* renderer)
{
	glDisable(GL_BLEND);

	sf::ConvexShape convex;

	// resize it to 5 points
	convex.setPointCount(body->VertexCount);

	convex.setFillColor(sf::Color::Red);

	for (int i=0; i<body->VertexCount; ++i)
	{
		convex.setPoint(i, body->Vertices[i]->Position);
	}

	renderer->Draw(convex);

	glEnable(GL_BLEND);
}