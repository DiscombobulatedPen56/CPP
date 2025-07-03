#pragma once
#include "Point.h"
#include "Rectangle.h"
#include <ostream>

class Square : public Rectangle{
public:
	Square();
	Square(Point topLeft, double sideLength);
	Square(Point topLeft, Point botRight);
	void Print(std::ostream& stream) override;
};