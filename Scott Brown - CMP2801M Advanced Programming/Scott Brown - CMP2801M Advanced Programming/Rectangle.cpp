#include "Rectangle.h"
#include <iterator>
#include <string>
#include <sstream>


Rectangle::Rectangle(int topLeftX, int topLeftY, int rHeight, int rWidth)
{
	leftTop = Point(topLeftX, topLeftY);
	height = rHeight;
	width = rWidth;
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}

void Rectangle::calculateArea()
{
	area = height * width;
}

void Rectangle::calculatePerimeter()
{
	perimeter = height * 2 + width * 2;
}

void Rectangle::move(int newX, int newY)
{
	leftTop = Point(newX, newY);
	calculatePoints();
	toString();
}

void Rectangle::calculatePoints()
{
	points.clear();
	points.push_back(&leftTop);
	points.push_back(new Point(leftTop.getX() + width, leftTop.getY()));
	points.push_back(new Point(leftTop.getX(), leftTop.getY() + height));
	points.push_back(new Point(leftTop.getX() + width, leftTop.getY() + height));
}

void Rectangle::scale(float scaleX, float scaleY)
{
	height = height * scaleY;
	width = width * scaleX;
}

std::string Rectangle::getPoints()
{
	std::string tmp = "Points[";

	std::vector<Point*>::iterator ptr;
	for (ptr = points.begin(); ptr < points.end(); ptr++)
	{
		tmp += "(" + std::to_string((*ptr)->getX()) + "," + std::to_string((*ptr)->getY()) + ")";
	}
	tmp += "]";
	return tmp;
}

std::string Rectangle::toString()
{
	std::stringstream tmp;
	tmp << "Rectangle[h=" + std::to_string(height) + ",w=" + std::to_string(height) + "]\n";
	tmp << getPoints().c_str();
	tmp << "\nArea=" + std::to_string(area) + " Perimeter=" + std::to_string(perimeter) + "\n";
	return tmp.str();
}

std::ostream& operator<<(std::ostream& os, Rectangle* c)
{
	std::string tmp = c->toString();
	os << tmp.c_str();
	return os;
}