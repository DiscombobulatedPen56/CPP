#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>
#include <format>

Circle::Circle(Point center, double r) : Ellipse(center, r, r)
{
}

void Circle::Print(std::ostream& stream) {
    stream << std::format("Circle: ({},{}), {}, {}", center.x, center.y, a, b) << std::endl;
}