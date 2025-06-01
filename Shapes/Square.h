#pragma once
#include "Point.h"
#include "Rectangle.h"

class Square : public Rectangle{
public:
	Square();
	Square(Point topLeft, double sideLength);
	Square(Point topLeft, Point botRight);
};