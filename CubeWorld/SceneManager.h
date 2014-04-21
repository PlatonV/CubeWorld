#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#pragma once

#include "SceneObject.h"
#include <vector>

class SceneManager
{
public:
	SceneManager(void) {}
	void Add(SceneObject* obj);
	void Update(sf::Time dt);
	~SceneManager(void) {}
private:
	std::vector<SceneObject*>::iterator objectsIT;

	std::vector<SceneObject*> mObjects;
};

#endif

