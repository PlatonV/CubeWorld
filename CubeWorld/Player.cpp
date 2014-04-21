#include "Player.h"

void Player::Init(void)
{
	mSize=50;

	sf::VertexArray quad(sf::Quads, 4);

	quad[0].position = sf::Vector2f(0,			0);
	quad[1].position = sf::Vector2f(mSize/2,	0);
	quad[2].position = sf::Vector2f(mSize/2,	mSize/2);
	quad[3].position = sf::Vector2f(0,			mSize/2);

	quad[0].color = sf::Color::Red;
	quad[1].color = sf::Color::Red;
	quad[2].color = sf::Color::Red;
	quad[3].color = sf::Color::Red;

	this->mPoints = quad;
}

void Player::MoveRight(void)
{
	Velocity.x++;
}

void Player::MoveLeft(void)
{
	Velocity.x--;
}

void Player::Jump(void)
{
	if(!mOnGround)
		Velocity.y-=50;
	mOnGround = false;
}