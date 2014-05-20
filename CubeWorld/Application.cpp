#include "Precompiled.h"

CW::Application::Application(void)
{
	Init();
}

void CW::Application::Init(void)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	m_Window = new sf::RenderWindow(sf::VideoMode(1280, 760), "Cube World", sf::Style::Default, settings);

	m_Window->setFramerateLimit(60);

	renderer = new Renderer(m_Window);

	sm.AddScreen(new MainMenuScreen(&sm, this));
	sm.AddScreen(new GameScreen(&sm, this));

	sm.GoToScreen("MainMenuScreen");

	if (!LoadBasicAssets()) {
		// TODO:: Give error message
	}

	m_DisplayText.setFont(ArialFont);
	m_DisplayText.setPosition(1175, 730);
	m_DisplayText.setCharacterSize(14);
	m_DisplayText.setString(sf::String("by Platon Vlad"));
	m_DisplayText.setColor(sf::Color::White);

	DBOUT("Inited");
}

int CW::Application::LoadBasicAssets(void)
{
	int returnCode = 1;

	if (!ArialFont.loadFromFile("arial.ttf")) {
		return 0;
	}

	return returnCode;
}

int	CW::Application::Run(void)
{
	// Enter the main loop
	MainLoop();

	return 0;
}

void CW::Application::MainLoop(void)
{
	// Clock used in restricting Update loop to a fixed rate
	sf::Clock updateClock;

	while (m_Window->isOpen())
	{
		sf::Event e;

		while (m_Window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				m_Window->close();
			}
		}

		m_Window->clear(sf::Color::Black);

		sm.Update(1);

		sm.Draw(renderer);

		m_Window->draw(m_DisplayText);

		m_Window->display();
	}
}

void CW::Application::Exit(void)
{
	m_Window->close();
}


CW::Application::~Application(void)
{
}
