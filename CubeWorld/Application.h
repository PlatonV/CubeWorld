#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once

#include "Precompiled.h"

namespace CW
{
	class Application
	{
	public:
		Application(void);

		int Run(void);

		void Exit(void);

		~Application(void);

	private:
		sf::Font ArialFont;

		sf::RenderWindow* m_Window;

		sf::Text m_DisplayText;

		Renderer* renderer;

		ScreenManager sm;

		void Init(void);
		int LoadBasicAssets(void);
		void MainLoop(void);
	};
}

#endif

