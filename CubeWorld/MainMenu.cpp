#include "Precompiled.h"

void CW::MainMenuScreen::Init(void)
{
	// TEXTS STUFF
	ArialFont.loadFromFile("arial.ttf");

	StartText.setFont(ArialFont);
	StartText.setPosition(75, 440);
	StartText.setCharacterSize(25);
	StartText.setString(sf::String("Press [Space] to start..."));
	StartText.setColor(sf::Color::White);

	HighScoreText.setFont(ArialFont);
	HighScoreText.setPosition(900, 30);
	HighScoreText.setCharacterSize(40);
	HighScoreText.setColor(sf::Color::White);

	// BACKGROUND
	BGTexture.loadFromFile("MenuBG.jpg");
	BGTexture.setSmooth(true);
	BGSprite.setTexture(BGTexture);

	// ICONS
	KeyboardTexture.loadFromFile("keyboard.png");
	KeyboardTexture.setSmooth(true);
	KeyboardSprite.setTexture(KeyboardTexture);
	KeyboardSprite.setPosition(1000, 50);

	JoystickTexture.loadFromFile("joystick.png");
	JoystickTexture.setSmooth(true);
	JoystickSprite.setTexture(JoystickTexture);
	JoystickSprite.setPosition(1000,200);

	// PARTICLES
	ParticleEmitterFactory* p_factory = new ParticleEmitterFactory();

	m_PE.AddEmitter(p_factory->CreateGlobalEmitter());

	fire = new Fire(860, 670);

	// MENU BUTTONS
	StartButton = new Button(Vector2(75, 450), "Start" , &ArialFont);
	OptionsButton = new Button(Vector2(75, 510), "Options" , &ArialFont);
	ExitButton = new Button(Vector2(75, 570), "Exit" , &ArialFont);

	StartButton->Select();

	// AUDIO
	if (soundBuffer.loadFromFile("menuClick.wav")) {
		clickSound.setBuffer(soundBuffer);
	}

	if (music.openFromFile("ambiance.ogg")) {
		music.setLoop(true);
		music.play();
	}

	// READ HIGHSCORE
	Highscore = 0;

	std::ifstream f("highscore.cbw");

	f>>Highscore;

	f.close();

	HighScoreText.setString(std::to_string(Highscore));
}

void CW::MainMenuScreen::MenuDown(void)
{
	if (StartButton->IsSelected)
	{
		StartButton->UnSelect();
		OptionsButton->Select();
		clickSound.play();
	}else if (OptionsButton->IsSelected)
	{
		OptionsButton->UnSelect();
		ExitButton->Select();
		clickSound.play();
	}
}

void CW::MainMenuScreen::MenuUp(void)
{
	if (OptionsButton->IsSelected)
	{
		OptionsButton->UnSelect();
		StartButton->Select();
		clickSound.play();
	}else if (ExitButton->IsSelected)
	{
		OptionsButton->Select();
		ExitButton->UnSelect();
		clickSound.play();
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

void CW::MainMenuScreen::NotifyKeyPressed(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Return)
	{
		Enter();
	}
	else if (key == sf::Keyboard::Up || key == sf::Keyboard::W)
	{
		MenuUp();
	}
	else if (key == sf::Keyboard::Down || key == sf::Keyboard::S)
	{
		MenuDown();
	}
}

void CW::MainMenuScreen::NotifyKeyReleased(sf::Keyboard::Key key)
{

}

void CW::MainMenuScreen::Update(float dt)
{
	std::ifstream f("highscore.cbw");

	f>>Highscore;

	f.close();

	HighScoreText.setString("Highscore: " + std::to_string(Highscore));

	m_PE.Update(dt);

	fire->Update(0.01f);

	StartButton->Update();
	OptionsButton->Update();
	OptionsButton->Update();
}

void CW::MainMenuScreen::Draw(Renderer* renderer)
{
	renderer->Draw(BGSprite);

	//renderer->Draw(KeyboardSprite);
	//renderer->Draw(JoystickSprite);

	m_PE.DrawAllParticles(renderer);

	renderer->Draw(HighScoreText);

	StartButton->Draw(renderer);
	OptionsButton->Draw(renderer);
	ExitButton->Draw(renderer);

	fire->Draw(renderer);
}