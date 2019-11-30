#pragma once
#include "Point.h"
#include<vector>

class Shape
{
private:
	float area;
	bool isCircular;
	Point leftTop;
	float perimeter;
	vector<Point> points;
protected:
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void calculatePoints() = 0;
	virtual void toString() = 0;
};