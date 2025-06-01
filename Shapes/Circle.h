#pragma once
#include "Point.h"
#include "Ellipse.h"
#include "Shape.h"

class Circle : public Ellipse{
public:
	Circle() = default;
	Circle(Point center, double r);
};