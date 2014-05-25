#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#pragma once

#include <vector>

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

		void NotifyKeyPressed(sf::Keyboard::Key key);
		void NotifyKeyReleased(sf::Keyboard::Key key);

		void Update(float dt);
		void Draw(Renderer* renderer);

		~GameScreen() {}

	private:
		int t;
		float speed;

		Application* App;

		Background* background;

		sf::Font ArialFont;

		sf::Text loadingText;
		sf::Text P1Text;
		sf::Text P2Text;
		sf::Text ScoreText;

		SmokeManager sm;

		std::vector<PhysicsBody*> boulders;

		ParticleEngine m_PE;
		PhysicsEngine m_PhyE;

		Terrain terrain;
		CeilingTerrain ceiling;

		Player* player1;
		Player2* player2;

		int Score;

		bool CheckCollision(PhysicsBody* body, sf::VertexArray verts);
	};
}

#endif