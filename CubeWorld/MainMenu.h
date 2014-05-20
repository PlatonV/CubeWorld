#ifndef MAINMENU_H
#define MAINMENU_H
#pragma once

namespace CW
{
	class Application;
	class Fire;
	class Screen;
	class Renderer;
	class ScreenManager;

	class MainMenuScreen : public Screen
	{
	public:
		MainMenuScreen() 
		{}

		MainMenuScreen(ScreenManager* screenManager, Application* app) 
		{
			App = app;
			m_SM = screenManager;
			Name = "MainMenuScreen";
			Init();
		}

		void Init(void);

		void MenuDown(void);
		void MenuUp(void);
		void Enter(void);

		void Update(float dt);
		void Draw(Renderer* renderer);

		~MainMenuScreen() {}

	private:
		Application* App;

		bool upressed;
		bool dpressed;

		sf::RenderWindow* m_ParentWindow;

		ParticleEngine m_PE;

		Fire* fire;

		Button* StartButton;
		Button* OptionsButton;
		Button* ExitButton;

		sf::Font ArialFont;
		sf::Text StartText;

		sf::Texture BGTexture;
		sf::Sprite BGSprite;
	};
}

#endif