#ifndef SKY_H
#define SKY_H
#pragma once

#include "Precompiled.h"

class Sky
{
public:
	Sky(void);

	void Draw(sf::RenderWindow& window);

	~Sky(void);
private:
	sf::VertexArray m_Vertices;
};

#endif

