#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>

Circle::Circle(Point center, double r) : Ellipse(center, r, r)
{
}
