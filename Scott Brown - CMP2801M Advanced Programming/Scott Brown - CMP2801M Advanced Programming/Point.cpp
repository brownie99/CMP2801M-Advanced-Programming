#include "Point.h"
#include <iostream>

Point::Point(int pX, int pY) 
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
