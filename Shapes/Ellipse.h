#pragma once
#include "Point.h"
#include <ostream>
#include <iostream>
#include "Shape.h"

class Ellipse : public Shape {
protected:
	Point center;
	double a, b;
public:
	Ellipse(Point center, double a, double b);
	double Area() override;
	double Perimeter() override;
	friend std::ostream& operator<<(std::ostream& stream, Ellipse& a);
};