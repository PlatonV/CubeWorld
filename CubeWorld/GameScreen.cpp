#include "Precompiled.h"

void CW::GameScreen::Init(void)
{
	ArialFont.loadFromFile("arial.ttf");

	loadingText.setFont(ArialFont);
	loadingText.setCharacterSize(30);
	loadingText.setPosition(560, 340);
	loadingText.setColor(sf::Color::White);
	loadingText.setString("Loading...");

	P1Text.setFont(ArialFont);
	P1Text.setCharacterSize(20);
	P1Text.setPosition(20, 650);
	P1Text.setColor(sf::Color::White);
	P1Text.setString("Player1 lives: 3");

	P2Text.setFont(ArialFont);
	P2Text.setCharacterSize(20);
	P2Text.setPosition(20, 690);
	P2Text.setColor(sf::Color::White);
	P2Text.setString("Player2 lives: 3");

	ScoreText.setFont(ArialFont);
	ScoreText.setCharacterSize(30);
	ScoreText.setPosition(560, 650);
	ScoreText.setColor(sf::Color::White);
	ScoreText.setString("000000");

	background = new Background("GameBG.jpg");

	terrain = Terrain(&m_PhyE);
	m_PhyE.sm = &sm;

	srand(time(0));

	speed = 10;
	Score = 0;

	player1 = new Player(300, 300, &terrain);

	if(sf::Joystick::isConnected(0))
	{
	//	player2 = new Player2(400, 300, &terrain);
	}
}

void CW::GameScreen::NotifyKeyPressed(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::W)
	{
		player1->Jump();
	}
}

void CW::GameScreen::NotifyKeyReleased(sf::Keyboard::Key key)
{

}


void CW::GameScreen::Update(float dt)
{
	Score += dt;
	speed += 0.001f;
	t++;
	int div = (int)(60 - (speed-10) * 25);
	if(div < 3) div = 3;
	if (t % div == 0)
	{
		PhysicsBody* a = PhysicsBody::CreateBoulder(rand() % 1300 + 700, 50, rand() % 250 + 50);
		boulders.push_back(a);
		m_PhyE.AddBody(a);
		t=0;
	}

	for (int i=0;i<boulders.size();i++)
	{
		if (boulders[i]->Vertices[0]->Position.x < -60)
		{
			m_PhyE.DeleteBody(boulders[i]);
			boulders.erase(boulders.begin() + i);
		}
	}

	background->Scroll(-speed * dt);
	terrain.Scroll(-speed * dt);
	ceiling.Scroll(-speed * dt);
	m_PhyE.Scroll(-speed + ((speed-10)) * dt);
	sm.Scroll(-speed);

	for (PhysicsBody* b : boulders)
	{
		if (m_PhyE.DetectCollision(b, player1->body))
		{
			player1->Velocity.y = -2;
			player1->Position.y = b->BoundingBox.MinY - 50;
			player1->Lives--;

			if (player1->Lives == -1)
			{
				int Highscore = 0;

				std::ifstream f("highscore.cbw");

				f>>Highscore;

				f.close();

				if (Score > Highscore)
				{
					std::ofstream g("highscore.cbw");

					g<<Score;

					g.close();
				}

				App->sm.GoToScreen("MainMenuScreen");
				App->Reset();
				return;
			}

			P1Text.setString("Player1 lives: " + std::to_string(player1->Lives));
		}
	}

	ScoreText.setString(std::to_string(Score));

	player1->Update(dt);
	//if(player2)
	//	player2->Update(dt);
	m_PhyE.Update();
	sm.Update(dt);
}

void CW::GameScreen::Draw(Renderer* renderer)
{
	background->Draw(renderer);

	ceiling.Draw(renderer);

	player1->Draw(renderer);
	//if(player2)
	//	player2->Draw(renderer);

	m_PhyE.Draw(renderer);

	sm.Draw(renderer);

	renderer->Draw(P1Text);
//	renderer->Draw(P2Text);
	renderer->Draw(ScoreText);
}
