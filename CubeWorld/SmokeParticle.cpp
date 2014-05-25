#include "Precompiled.h"

CW::SmokeParticle::SmokeParticle(float _x, float _y, float _r, float _g, float _b, float inten)
{
	r=_r;
	g=_g;
	b=_b;

	intensity = inten;

	Position.x = _x;
	Position.y = _y - 150;

	Velocity.x = (float)(rand() % 4);

	int r = rand() % 10;
	r = r<5 ? r=1 : r=-1;
	Velocity.x *= r;

	Velocity.y = (float)(-rand() % 4);
	r = rand() % 10;
	r = r<5 ? r=1 : r=-1;
	Velocity.y *= r;

	ttl=0;
}

void CW::SmokeParticle::Draw(Renderer* renderer)
{
	renderer->BeginShader(&renderer->LightShader);

    glBlendFunc(1, 1);

	renderer->CurrentShader->setParameter("color", 150,150,150,100);
	renderer->CurrentShader->setParameter("lightPos", Position);
	renderer->CurrentShader->setParameter("intensity", intensity/100000);

	sf::RectangleShape rectangle(sf::Vector2f(1760, 780));

	rectangle.setPosition(0, 0);
	rectangle.setFillColor(sf::Color::White);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	renderer->Draw(rectangle);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	renderer->EndShader();

	ttl++;

	/*glDisable(GL_BLEND);

	sf::RectangleShape r(sf::Vector2f(5,5));
	r.setFillColor(sf::Color::Black);
	r.setPosition(Position.x, Position.y);
	renderer->Draw(r);

	glEnable(GL_BLEND);*/
}