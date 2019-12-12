#pragma once
#include "Shape.h"
#include "Movable.h"

class Circle : public Shape, public Movable
{
private:
	float radius;
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
public:
	Circle(int topLeftX, int topLeftRightx, int cRadius);
	std::string getPoints();
	std::string toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
	friend std::ostream& operator<<(std::ostream& os, Circle* c);
};
