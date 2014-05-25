#include "Precompiled.h"

void CW::SceneManager::Add(SceneObject* obj)
{
	this->mObjects.push_back(obj);
}

void CW::SceneManager::Update(sf::Time dt)
{
	for (objectsIT = mObjects.begin(); objectsIT != mObjects.end(); objectsIT++)
	{
		
	}
}
