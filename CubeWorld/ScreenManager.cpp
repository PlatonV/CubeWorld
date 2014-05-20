#include "Precompiled.h"


CW::ScreenManager::ScreenManager(void)
{
}

void CW::ScreenManager::AddScreen(Screen* screen)
{
	m_Screens.push_back(screen);
}

void CW::ScreenManager::GoToScreen(char* screenName)
{
	// Iterate trough all the screens
	for (Screen* s : m_Screens)
	{
		// If a screen with the requested name is found then set it as the current screen
		if (s->Name == screenName)
		{
			m_CurrentScreen = s;
		}
	}
}

void CW::ScreenManager::Update(float dt)
{
	m_CurrentScreen->Update(dt);
}

void CW::ScreenManager::Draw(Renderer* renderer)
{
	int a = 3;

	m_CurrentScreen->Draw(renderer);
}

CW::ScreenManager::~ScreenManager(void)
{
}
