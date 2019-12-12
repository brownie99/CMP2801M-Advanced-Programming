#pragma once
#include "Shape.h"
#include "Movable.h"

class Square : public Shape, public Movable
{
private:
	int edge;
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
public:
	Square (int topLeftX, int topLeftY, int edgeLength);
	std::string getPoints();
	std::string toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
	friend std::ostream& operator<<(std::ostream& os, Square* c);

};
