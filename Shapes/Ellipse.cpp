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

std::ostream& operator<<(std::ostream& stream, Ellipse& a) {
    stream << std::format("Ellipse: ({},{}), {}, {}", a.center.x, a.center.y, a.a, a.b) << std::endl;
    return stream;
}
