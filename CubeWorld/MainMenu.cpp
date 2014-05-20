#include "Precompiled.h"

void CW::MainMenuScreen::Init(void)
{
	ArialFont.loadFromFile("arial.ttf");

	StartText.setFont(ArialFont);
	StartText.setPosition(75, 440);
	StartText.setCharacterSize(25);
	StartText.setString(sf::String("Press [Space] to start..."));
	StartText.setColor(sf::Color::White);

	BGTexture.loadFromFile("MenuBG.jpg");
	BGTexture.setSmooth(true);
	BGSprite.setTexture(BGTexture);

	ParticleEmitterFactory* p_factory = new ParticleEmitterFactory();

	m_PE.AddEmitter(p_factory->CreateGlobalEmitter());

	fire = new Fire(860, 670);

	StartButton = new Button(Vector2(75, 450), "Start" , &ArialFont);
	OptionsButton = new Button(Vector2(75, 510), "Options" , &ArialFont);
	ExitButton = new Button(Vector2(75, 570), "Exit" , &ArialFont);

	StartButton->Select();

	upressed = false;
	dpressed = false;
}

void CW::MainMenuScreen::MenuDown(void)
{
	if (StartButton->IsSelected)
	{
		StartButton->UnSelect();
		OptionsButton->Select();
	}else if (OptionsButton->IsSelected)
	{
		OptionsButton->UnSelect();
		ExitButton->Select();
	}
}

void CW::MainMenuScreen::MenuUp(void)
{
	if (OptionsButton->IsSelected)
	{
		OptionsButton->UnSelect();
		StartButton->Select();
	}else if (ExitButton->IsSelected)
	{
		OptionsButton->Select();
		ExitButton->UnSelect();
	}
}

void CW::MainMenuScreen::Enter(void)
{
	if (StartButton->IsSelected)
	{
		m_SM->GoToScreen("GameScreen");
	}else if (OptionsButton->IsSelected)
	{
		
	}else if (ExitButton->IsSelected)
	{
		App->Exit();
	}
}

void CW::MainMenuScreen::Update(float dt)
{
	m_PE.Update(dt);

	fire->Update(0.01f);

	StartButton->Update();
	OptionsButton->Update();
	OptionsButton->Update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		Enter();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!upressed) {
			MenuUp();
			upressed = true;
		}
	}
	else {
		upressed = false;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (!dpressed) {
			MenuDown();
			dpressed = true;
		}
	}
	else {
		dpressed = false;
	}
}

void CW::MainMenuScreen::Draw(Renderer* renderer)
{
	renderer->Draw(BGSprite);

	m_PE.DrawAllParticles(renderer);

	StartButton->Draw(renderer);
	OptionsButton->Draw(renderer);
	ExitButton->Draw(renderer);

	fire->Draw(renderer);

	//renderer->Draw(StartText);
}