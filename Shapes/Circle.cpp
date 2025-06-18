#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>
#include <format>

Circle::Circle(Point center, double r) : Ellipse(center, r, r)
{
}

std::ostream& operator<<(std::ostream& stream, Circle& a) {
    stream << std::format("Circle: ({},{}), {}, {}", a.center.x, a.center.y, a.a, a.b) << std::endl;
    return stream;
}