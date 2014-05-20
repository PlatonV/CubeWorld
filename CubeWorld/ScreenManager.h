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
		ScreenManager(void);

		void AddScreen(Screen* screen);
		void GoToScreen(char* screenName);

		void Update(float dt);
		void Draw(Renderer* renderer);

		~ScreenManager(void);

	private:
		Screen* m_CurrentScreen;

		std::vector<Screen*> m_Screens;
	};
}

#endif

