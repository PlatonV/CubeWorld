#ifndef MAINMENU_H
#define MAINMENU_H
#pragma once

#include <SFML\Audio.hpp>

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

		void NotifyKeyPressed(sf::Keyboard::Key key);
		void NotifyKeyReleased(sf::Keyboard::Key key);

		void Update(float dt);
		void Draw(Renderer* renderer);

		~MainMenuScreen() {}

	private:
		int Highscore;

		Application* App;

		sf::RenderWindow* m_ParentWindow;

		ParticleEngine m_PE;

		Fire* fire;

		Button* StartButton;
		Button* OptionsButton;
		Button* ExitButton;

		sf::Music music;
		sf::SoundBuffer soundBuffer;

		sf::Sound clickSound;

		sf::Font ArialFont;
		sf::Text StartText;
		sf::Text HighScoreText;

		sf::Texture BGTexture;
		sf::Sprite BGSprite;

		sf::Texture KeyboardTexture;
		sf::Sprite KeyboardSprite;

		sf::Texture JoystickTexture;
		sf::Sprite JoystickSprite;
	};
}

#endif