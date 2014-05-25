#include "Precompiled.h"


CW::Renderer::Renderer(sf::RenderWindow* window)
{
	m_Window = window;

	LightShader.loadFromFile("Vertex.vert", sf::Shader::Vertex);
	LightShader.loadFromFile("Light.frag", sf::Shader::Fragment);
}

void CW::Renderer::BeginShader(sf::Shader* shader)
{
	m_UsingShader = true;

	CurrentShader = shader;
}

void CW::Renderer::EndShader(void)
{
	m_UsingShader = false;

	CurrentShader = 0;
}

void CW::Renderer::Draw(const sf::Drawable& drawable, sf::RenderStates states)
{
	if (m_UsingShader)
	{
		m_Window->draw(drawable, CurrentShader);
	}
	else
	{
		m_Window->draw(drawable, states);
	}
}

void CW::Renderer::Draw(const sf::Vertex* vertices, unsigned int vertexCount, sf::PrimitiveType type, sf::RenderStates states)
{
	if (m_UsingShader)
	{
		m_Window->draw(vertices, vertexCount, type, CurrentShader);
	}
	else
	{
		m_Window->draw(vertices, vertexCount, type, states);
	}
}


CW::Renderer::~Renderer(void)
{
}
