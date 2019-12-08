#include "Point.h"

Point::Point(int pX=0, int pY=0) 
{
	x = pX;
	y = pY;
};

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}
