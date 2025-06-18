#pragma once
#include "Point.h"
#include "Rectangle.h"
#include <ostream>

class Square : public Rectangle{
public:
	Square();
	Square(Point topLeft, double sideLength);
	Square(Point topLeft, Point botRight);
	friend std::ostream& operator<<(std::ostream& stream, Square& a);
};