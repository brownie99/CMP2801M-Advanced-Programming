#include "Square.h"

Square::Square(int topLeftX, int topLeftY, int edgeLength)
{
	leftTop = Point(topLeftX, topLeftY);
	edge = edgeLength;
	calculatePoints();
	calculateArea;
	calculatePerimeter();
}

void Square::calculateArea()
{
	area = edge * edge;
}

void Square::calculatePerimeter()
{
	perimeter = edge * 4;
}

void Square::move(int newX, int newY)
{
	leftTop = Point(newX, newY);
	calculatePoints();
	toString();
}

void Square::calculatePoints()
{
	points.clear();
	points.push_back(leftTop);
	points.push_back(Point(leftTop.getX()+edge, leftTop.getY()));
	points.push_back(Point(leftTop.getX(), leftTop.getY()+edge));
	points.push_back(Point(leftTop.getX()+edge, leftTop.getY()+edge));
}

void Square::toString()
{
	std::cout << "Square[e=" << edge << "]" << std::endl;
	std::cout << "Points[(" << points[0].getX() << "," << points[0].getY() << ")(" << points[1].getX() << "," << points[1].getY() << ")(" << points[2].getX() << "," << points[2].getY() << ")(" << points[3].getX() << "," << points[3].getY() << ")]" << std::endl;
	std::cout << "Area=" << area << " Perimeter" << perimeter << std::endl;
}