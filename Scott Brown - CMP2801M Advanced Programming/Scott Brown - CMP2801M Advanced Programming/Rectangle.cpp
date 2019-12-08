#include "Rectangle.h"

Rectangle::Rectangle(int topLeftX, int topLeftY, int rHeight, int rWidth)
{
	leftTop = Point(topLeftX, topLeftY);
	height = rHeight;
	width = rWidth;
	calculatePoints();
	calculateArea;
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
	points.push_back(leftTop);
	points.push_back(Point(leftTop.getX() + width, leftTop.getY()));
	points.push_back(Point(leftTop.getX(), leftTop.getY() + height));
	points.push_back(Point(leftTop.getX() + width, leftTop.getY() + height));
}

void Rectangle::toString()
{
	std::cout << "Rectangle[h=" << height << ",w=" << width << "]" << std::endl;
	std::cout << "Points[(" << points[0].getX() << "," << points[0].getY() << ")(" << points[1].getX() << "," << points[1].getY() << ")(" << points[2].getX() << "," << points[2].getY() << ")(" << points[3].getX() << "," << points[3].getY() << ")]" << std::endl;
	std::cout << "Area=" << area << " Perimeter" << perimeter << std::endl;
}