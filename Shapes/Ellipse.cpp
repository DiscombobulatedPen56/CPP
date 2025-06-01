#define _USE_MATH_DEFINES
#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(Point center, double a, double b) : center(center), a(a), b(b)
{
}

double Ellipse::Area() {
	return a * b * M_PI;
}

double Ellipse::Perimeter() {
	return M_PI * (a + b);
}