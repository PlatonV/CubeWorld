#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H
#pragma once

#include <SFML\Graphics.hpp>

class SceneObject : public sf::Transformable
{
public:
	bool isAffectedByGravity;

	sf::Vector2f Velocity;

	SceneObject(void){}
	SceneObject(bool affectedByGravity) 
		: isAffectedByGravity(affectedByGravity)
	{}
	void Update(void);
	~SceneObject(void){}
};

#endif
