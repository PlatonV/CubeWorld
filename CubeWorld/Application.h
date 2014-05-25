#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once

namespace CW
{
	class Application
	{
	public:
		ScreenManager sm;

		Application(void);

		int Run(void);

		void Reset(void);

		void Exit(void);

		~Application(void);

	private:
		sf::Font ArialFont;

		sf::RenderWindow* m_Window;

		sf::Text m_DisplayText;

		Renderer* renderer;

		void Init(void);
		int LoadBasicAssets(void);
		void MainLoop(void);
	};
}

#endif

