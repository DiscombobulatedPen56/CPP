#pragma once

class Shape {
public:
	virtual ~Shape() = default;
	virtual double Area() = 0;
	virtual double Perimeter() = 0;
};