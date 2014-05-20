#ifndef BUTTON_H
#define BUTTON_H
#pragma once

namespace CW
{
	class Vector2;
	class Renderer;

	class Button
	{
	public:
		bool	IsSelected;

		Button(const Vector2& position , sf::String text, sf::Font* font);

		void Select(void);
		void UnSelect(void);

		void Update(void);
		void Draw(Renderer* renderer);

		~Button(void) {}
	private:
		sf::RenderWindow* m_ParentWindow;
		Vector2 m_Position;

		sf::String m_Text;
		sf::Text t;
	};
}

#endif