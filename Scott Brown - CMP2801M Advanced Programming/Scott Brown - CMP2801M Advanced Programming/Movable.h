#pragma once

class Movable
{
public:
	virtual void move(int newX, int newY) = 0;
	virtual void scale(float scaleX, float scaleY) = 0;
};
