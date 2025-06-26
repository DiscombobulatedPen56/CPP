#include "Ellipse.h"
#define _USE_MATH_DEFINES
#include "Ellipse.h"
#include <format>
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

void Ellipse::Print(std::ostream& stream)
{
	stream << std::format("Ellipse: ({},{}), {}, {}", center.x, center.y, a, b) << std::endl;
}

