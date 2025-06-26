#pragma once
#include <ostream>

class Shape {
public:
	virtual ~Shape() = default;
	virtual double Area() = 0;
	virtual double Perimeter() = 0;
	virtual void Print(std::ostream& stream) = 0;
	friend std::ostream& operator<<(std::ostream& stream, Shape& shape);
};
