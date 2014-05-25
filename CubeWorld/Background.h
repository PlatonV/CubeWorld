#ifndef BACKGROUND_H
#define BACKGROUND_H
#pragma once

#include <SFML\Graphics.hpp>
#include <string>

namespace CW
{
	class Renderer;

	class Background
	{
	public:
		Background(std::string path)
		{ 
			m_FilePath = path;

			Load(); 
		}

		void Load(void);
		void Scroll(float value);
		void Draw(Renderer* renderer);

		~Background(void){}

	private:
		std::string m_FilePath;

		sf::Texture BackgroundTexture;

		sf::Sprite Background1Sprite;
		sf::Sprite Background2Sprite;
	};
}

#endif

