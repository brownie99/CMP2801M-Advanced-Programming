#pragma once
#include "Shape.h"
#include "Movable.h"
#include "Error.h"

class Rectangle : public Shape, public Movable
{
	int width;
	int height;
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
public:
	Rectangle(int topLeftX, int topLeftY, int rHeight, int rWidth);
	std::string getPoints();
	std::string toString();
	void move (int newX, int newY);
	void scale(float scaleX, float scaleY);
	friend std::ostream& operator<<(std::ostream& os, Rectangle* c);

};
