#ifndef SCREEN_H
#define SCREEN_H
#pragma once

namespace CW
{
	class Renderer;
	class ScreenManager;

	class Screen
	{
	public:
		std::string Name;

		Screen()
		{}

		virtual void NotifyKeyPressed(sf::Keyboard::Key key) = 0;
		virtual void NotifyKeyReleased(sf::Keyboard::Key key) = 0;

		virtual void Update(float dt) = 0;
		virtual void Draw(Renderer* renderer) = 0;

		~Screen(void) {}

	protected:
		ScreenManager* m_SM;
	};
}

#endif
