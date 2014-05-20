#ifndef RENDERER_H
#define RENDERER_H	
#pragma once

#include "Precompiled.h"

namespace CW
{
	class Renderer
	{
	public:
		sf::Shader* CurrentShader;
		sf::Shader	LightShader;

		Renderer(sf::RenderWindow* window);

		void BeginShader(sf::Shader* shader);
		void EndShader(void);

		void Draw(const sf::Drawable& drawable, sf::RenderStates states = sf::RenderStates::Default);
		void Draw(const sf::Vertex* vertices, unsigned int vertexCount, sf::PrimitiveType type, sf::RenderStates states = sf::RenderStates::Default);

		~Renderer(void);
	private:
		sf::RenderWindow* m_Window;	

		bool m_UsingShader;
	};
}

#endif

