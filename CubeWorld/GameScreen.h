#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#pragma once

namespace CW
{
	class Application;
	class Screen;
	class Renderer;
	class ScreenManager;
	class ParticleEngine;
	class PhysicsEngine;

	class GameScreen : public Screen
	{
	public:
		GameScreen() 
		{}

		GameScreen(ScreenManager* screenManager, Application* app) 
		{
			App = app;
			m_SM = screenManager;
			Name = "GameScreen";
			Init();
		}

		void Init(void);

		void Update(float dt);
		void Draw(Renderer* renderer);

		~GameScreen() {}

	private:
		Application* App;

		ParticleEngine m_PE;
		PhysicsEngine m_PhyE;
	};
}

#endif