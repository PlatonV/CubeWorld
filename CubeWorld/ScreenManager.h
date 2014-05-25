#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#pragma once

#include <vector>

namespace CW
{
	class Screen;

	class ScreenManager
	{
	public:
		std::vector<Screen*> m_Screens;

		ScreenManager(void);

		void AddScreen(Screen* screen);
		void GoToScreen(char* screenName);

		void NotifyKeyPressed(sf::Keyboard::Key key);
		void NotifyKeyReleased(sf::Keyboard::Key key);

		void Update(float dt);
		void Draw(Renderer* renderer);

		~ScreenManager(void);

	private:
		Screen* m_CurrentScreen;
	};
}

#endif

