#pragma once
#include "Point.h"
#include <vector>
#include <iostream>
#include <string>
#include <strstream>

class Shape
{
protected:
	float area;
	bool isCircular;
	Point leftTop;
	float perimeter;
	std::vector<Point*> points;
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void calculatePoints() = 0;
	virtual std::string getPoints() = 0;
public:
	virtual std::string toString() = 0;
	
};