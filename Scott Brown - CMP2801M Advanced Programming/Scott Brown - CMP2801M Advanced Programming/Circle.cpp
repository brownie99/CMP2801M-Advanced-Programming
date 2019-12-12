#include "Circle.h"
#include "Error.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iterator>
#include <exception>
#include <sstream>
#include <typeinfo>

Circle::Circle(int topLeftX, int topLeftY, int cRadius)
{
	leftTop = Point(topLeftX, topLeftY);
	radius = cRadius;
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}

void Circle::calculateArea()
{
	area = M_PI*radius*radius;
}

void Circle::calculatePerimeter()
{
	perimeter = M_PI * 2 * radius;
}

void Circle::move(int newX, int newY)
{
	leftTop = Point(newX, newY);
	calculatePoints();
	toString();
}

void Circle::scale(float scaleX, float scaleY)
{
	try
	{
		if (scaleX != scaleY)
		{
			throw errorClass("X and Y scale and not the same");
		}
		radius = radius * scaleX;
		calculatePoints();
		calculateArea();
		calculatePerimeter();
		toString();
	}
	catch (errorClass e)
	{
		std::cout << e.getErrMsg().c_str();
	}
}

void Circle::calculatePoints()
{
	points.push_back(&leftTop);
	points.push_back(new Point(leftTop.getX() + radius*2, leftTop.getY() + radius*2));
}

std::string Circle::getPoints()
{
	std::ostringstream tmp;
	tmp << "Points[";
	std::vector<Point*>::iterator it;
	for (it = points.begin(); it < points.end(); it++)
	{
		tmp << "(" << (*it)->getX() << "," << (*it)->getY() << ")";
	}
	tmp << "]";
	return tmp.str();
}

std::string Circle::toString()
{
	std::ostringstream tmp;
	tmp << "Circle[r=" + std::to_string(radius) + "]\n";
	tmp << "" + getPoints();
	tmp << "\nArea=" + std::to_string(area) + " Perimeter=" + std::to_string(perimeter) + "\n";
	return tmp.str();
}

std::ostream& operator<<(std::ostream& os, Circle* c)
{
	std::string tmp = c->toString();
	os << tmp.c_str();
	return os;
}