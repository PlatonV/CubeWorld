#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#pragma once

namespace CW
{
	class BoundingBox
	{
	public:
		int	MinX;
		int MinY;
		int MaxX;
		int MaxY;
		int Width;
		int Height;

		BoundingBox(void);
		BoundingBox(int x, int y, int width, int height);

		bool Intersects(BoundingBox& with);
		static bool CheckIntersection(BoundingBox* a, BoundingBox* b);

		~BoundingBox(void);
	};
}

#endif

