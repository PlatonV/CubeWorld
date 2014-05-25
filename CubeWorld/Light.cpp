#include "Precompiled.h"

CW::Light::Light(float _x, float _y, float _r, float _g, float _b, float inten)
{
	r=_r;
	g=_g;
	b=_b;

	intensity = inten;

	Position.x = _x;
	Position.y = _y;

	Velocity.x = (float)(rand() % 4);
	Velocity.x *= 10;

	int r = rand() % 10;
	r = r<5 ? r=1 : r=-1;
	Velocity.x *= r;

	Velocity.y = (float)(-rand() % 12 - 4);
	Velocity.y *= 10;
}

void CW::Light::Draw(Renderer* renderer)
{
	renderer->BeginShader(&renderer->LightShader);

    glBlendFunc(1, 1);

	renderer->CurrentShader->setParameter("color", r*255,g*180,b*255,255);
	renderer->CurrentShader->setParameter("lightPos", Position);
	renderer->CurrentShader->setParameter("intensity", intensity/100);

	sf::RectangleShape rectangle(sf::Vector2f(1760, 780));

	rectangle.setPosition(0, 0);
	rectangle.setFillColor(sf::Color::White);

	renderer->Draw(rectangle);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	renderer->EndShader();
}
