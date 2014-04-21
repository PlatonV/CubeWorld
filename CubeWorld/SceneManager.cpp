#include "SceneManager.h"

void SceneManager::Add(SceneObject* obj)
{
	this->mObjects.push_back(obj);
}

void SceneManager::Update(sf::Time dt)
{
	for (objectsIT = mObjects.begin(); objectsIT != mObjects.end(); objectsIT++)
	{
		if((*objectsIT)->isAffectedByGravity)
		{
			(*objectsIT)->Velocity.y+=3;
		}

		(*objectsIT)->move((*objectsIT)->Velocity * dt.asSeconds());

		if ((*objectsIT)->getPosition().y > 500 && (*objectsIT)->isAffectedByGravity)
		{
			(*objectsIT)->setPosition((*objectsIT)->getPosition().x, 500);
			(*objectsIT)->Velocity.y = 0;

		}
	}
}
