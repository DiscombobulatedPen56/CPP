#pragma once
#include "Point.h"
#include "Shape.h"

class Ellipse : public Shape {
protected:
	Point center;
	double a, b;
public:
	Ellipse(Point center, double a, double b);
	double Area() override;
	double Perimeter() override;
};