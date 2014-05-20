#ifndef MATH_H
#define MATH_H
#pragma once

#include <SFML\System.hpp>

#define MIN( A, B ) ( (A) < (B) ? (A) : (B) )
#define MAX( A, B ) ( (A) > (B) ? (A) : (B) )

namespace CW
{
	class Vector2 : public sf::Vector2<float>
	{
	public:
		Vector2(float px = 0.0f, float py = 0.0f) 
		{
			x = px;
			y = py;
		}

		~Vector2() { }

		Vector2 operator*( float scalar ) 
		{
			return Vector2( x*scalar, y*scalar ); 
		}
		Vector2 operator/( float scalar )
		{
			return Vector2( x/scalar, y/scalar ); 
		}
		Vector2 operator+( Vector2 rhs ) 
		{ 
			return Vector2( x + rhs.x, y + rhs.y ); 
		}
		Vector2 operator-( Vector2 rhs ) 
		{
			return Vector2( x - rhs.x, y - rhs.y ); 
		}
		Vector2 operator-() 
		{
			return Vector2( -x, -y ); 
		}
		float operator*( Vector2 rhs ) { return x*rhs.x + y*rhs.y; }
		void operator=( Vector2 rhs ) { x = rhs.x; y = rhs.y; }
		void operator+=( Vector2 rhs ) { x += rhs.x; y += rhs.y; }
		void operator-=( Vector2 rhs ) { x -= rhs.x; y -= rhs.y; }
		void operator*=( float scalar ) { x *= scalar; y *= scalar; }
		void operator/=( float scalar ) { x /= scalar; y /= scalar; }

		bool operator==( Vector2 rhs ) { return x == rhs.x && y == rhs.y; }
		bool operator!=( Vector2 rhs ) { return x != rhs.x || y != rhs.y; }

		float Length() { return sqrtf( x*x + y*y ); }
		float LengthSq() { return x*x + y*y; }

		void Normalize() {
			float Len = 1.0/sqrtf( x*x + y*y );

			x *= Len;
			y *= Len;
		}
	};

	inline int SGN(float x)
	{
		return (x > 0) - (x < 0);
	}
}

#endif
