#pragma once
#include "Point.h"
#include "Shape.h"
#include <ostream>

class Rectangle : public Shape{
protected:
	Point topLeft;
	Point botRight;
public:
	Rectangle();
	Rectangle(Point topLeft, Point botRight);
	Rectangle(Point topLeft, double width, double height);
	double Area() override;
	double Perimeter() override;
	double Width();
	double Height();
	void Print(std::ostream& stream) override;
};
