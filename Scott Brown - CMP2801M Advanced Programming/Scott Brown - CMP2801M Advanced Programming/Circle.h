#pragma once
#include "Shape.h"
#include "Movable.h"

class Circle : public Shape, public Movable
{
private:
	int radius;
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
public:
	void toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
};
