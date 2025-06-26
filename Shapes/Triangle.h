#pragma once
#include "Point.h"
#include "Shape.h"

class Triangle : public Shape{
	Point a, b, c;
public:
	Triangle() = default;
	Triangle(Point a, Point b, Point c);
	double Area() override;
	double Perimeter() override;
	void Print(std::ostream& stream) override;
};