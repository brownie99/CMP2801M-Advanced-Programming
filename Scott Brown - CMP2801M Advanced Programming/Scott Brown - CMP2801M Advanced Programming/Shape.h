#pragma once
#include "Point.h"
#include <vector>
#include <iostream>

class Shape
{
protected:
	int area;
	bool isCircular;
	Point leftTop;
	float perimeter;
	std::vector<Point> points;
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void calculatePoints() = 0;
public:
	virtual void toString() = 0;
	
};