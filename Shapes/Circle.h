#pragma once
#include "Point.h"
#include "Ellipse.h"
#include <ostream>
#include "Shape.h"

class Circle : public Ellipse{
public:
	Circle() = default;
	Circle(Point center, double r);
	friend std::ostream& operator<<(std::ostream& stream, Circle& a);
};

