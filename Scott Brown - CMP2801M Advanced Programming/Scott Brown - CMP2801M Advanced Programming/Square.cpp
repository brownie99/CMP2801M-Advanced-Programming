#include "Square.h"
#include "Error.h"
#include <iterator>
#include <string>
#include <sstream>


Square::Square(int topLeftX, int topLeftY, int edgeLength)
{
	leftTop = Point(topLeftX, topLeftY);
	edge = edgeLength;
	calculatePoints();
	calculateArea();
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
	points.push_back(&leftTop);
	points.push_back(new Point(leftTop.getX()+edge, leftTop.getY()));
	points.push_back(new Point(leftTop.getX(), leftTop.getY()+edge));
	points.push_back(new Point(leftTop.getX()+edge, leftTop.getY()+edge));
}

void Square::scale(float scaleX, float scaleY)
{
	try
	{
		if (scaleX != scaleY)
		{
			throw errorClass("X and Y scale and not the same");
		}
		edge = edge * scaleX;
	}
	catch (errorClass e)
	{
		std::cout << e.getErrMsg().c_str();
	}
}

std::string Square::getPoints()
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

std::string Square::toString()
{
	std::stringstream tmp;
	tmp << "Circle[e=" + std::to_string(edge) + "]\n";
	tmp << getPoints().c_str();
	tmp << "\nArea=" + std::to_string(area) + " Perimeter=" + std::to_string(perimeter) + "\n";
	return tmp.str();
}

std::ostream& operator<<(std::ostream& os, Square* c)
{
	std::string tmp = c->toString();
	os << tmp.c_str();
	return os;
}