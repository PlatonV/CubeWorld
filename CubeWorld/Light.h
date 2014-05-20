#ifndef LIGHT_H
#define LIGHT_H
#pragma once

namespace CW
{
	class Renderer;
	class Vector2;

	class Light
	{
	public:
		Vector2 Position;
		float r;
		float g;
		float b;
		float intensity;
		Vector2 Velocity;

		Light() {}
		Light(float _x, float _y, float _r, float _g, float _b, float inten);

		void Draw(Renderer* renderer);

		~Light(void) {}
	};
}

#endif
