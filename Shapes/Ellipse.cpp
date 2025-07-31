#include "Ellipse.h"
#define _USE_MATH_DEFINES
#include "Ellipse.h"
#include <format>
#include <cmath>

Ellipse::Ellipse(Point center, double a, double b) : center(center), a(a), b(b)
{
}

double Ellipse::Area() {
	return a * b * 3.141592653589;
}

double Ellipse::Perimeter() {
	return 3.141592653589 * (a + b);
}

void Ellipse::Print(std::ostream& stream)
{
	stream << std::format("Ellipse: ({},{}), {}, {}", center.x, center.y, a, b) << std::endl;
}

