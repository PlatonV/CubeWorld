#include "Precompiled.h"
#include "BoundingBox.h"


CW::BoundingBox::BoundingBox(void)
{
}

CW::BoundingBox::BoundingBox(int minx, int miny, int width, int height)
{
	MinX		=	minx;
	MinY		=	miny;
	MaxX		=	minx + width;
	MaxY		=	miny + height;
}

bool CW::BoundingBox::Intersects(BoundingBox& with)
{
	with.Width = with.MaxX - with.MinX;
	with.Height = with.MaxY - with.MinY;

	Width = MaxX - MinX;
	Height = MaxY - MinY;

	return (std::abs(this->MinX - with.MinX) * 2 < (this->Width + with.Width)) && 
		(std::abs(this->MinY - with.MinY) * 2 < (this->Height + with.Height));
}

bool CW::BoundingBox::CheckIntersection(BoundingBox* a, BoundingBox* b)
{
	return ( a->MinX <= b->MaxX ) && ( a->MinY <= b->MaxY ) && ( a->MaxX >= b->MinX ) && ( b->MaxY >= a->MinY );
}


CW::BoundingBox::~BoundingBox(void)
{
}
