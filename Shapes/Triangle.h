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
	friend std::ostream& operator<<(std::ostream& stream, Triangle& a);
};