#include "Precompiled.h"

CW::Button::Button(const Vector2& position , sf::String text, sf::Font* font)
{
	m_Position = position;
	m_Text = text;

	IsSelected = false;

	t.setFont(*font);
	t.setPosition(position);
	t.setCharacterSize(30);
	t.setColor(sf::Color::White);
	t.setString(text);
}

void CW::Button::Select(void)
{
	IsSelected = true;

	t.setPosition(t.getPosition().x, t.getPosition().y - 20);
	t.setCharacterSize(60);
	t.setColor(sf::Color(255, 200, 0, 255));
}

void CW::Button::UnSelect(void)
{
	IsSelected = false;

	t.setPosition(t.getPosition().x, t.getPosition().y + 20);
	t.setCharacterSize(30);
	t.setColor(sf::Color(255, 255, 255, 255));
}

void CW::Button::Update(void)
{
	
}

void CW::Button::Draw(Renderer* renderer)
{
	renderer->Draw(t);
}