#pragma once
#include "Point.h"
#include "Ellipse.h"
#include <ostream>
#include "Shape.h"
#include <format>

class Circle : public Ellipse{
public:
	Circle() = default;
	Circle(Point center, double r);
	void Print(std::ostream& stream) override;
};

