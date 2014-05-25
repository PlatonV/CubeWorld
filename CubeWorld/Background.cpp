#include "Precompiled.h"

void CW::Background::Load(void)
{
	BackgroundTexture.loadFromFile(m_FilePath);

	Background1Sprite.setTexture(BackgroundTexture);
	Background2Sprite.setTexture(BackgroundTexture);

	Background2Sprite.setPosition(BackgroundTexture.getSize().x, 50);
}

void CW::Background::Scroll(float value)
{
	Background1Sprite.setPosition(Background1Sprite.getPosition().x + value, Background2Sprite.getPosition().y);

	Background2Sprite.setPosition(Background2Sprite.getPosition().x + value, Background2Sprite.getPosition().y);

	if (Background2Sprite.getPosition().x < 0)
	{
		Background1Sprite.setPosition(Background2Sprite.getPosition().x + BackgroundTexture.getSize().x, 50);
	}
	if (Background1Sprite.getPosition().x < 0)
	{
		Background2Sprite.setPosition(Background1Sprite.getPosition().x + BackgroundTexture.getSize().x, 50);
	}
}

void CW::Background::Draw(Renderer* renderer)
{
	renderer->Draw(Background1Sprite);
	renderer->Draw(Background2Sprite);
}

