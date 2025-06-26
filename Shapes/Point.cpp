#include "Point.h"
#include <cmath>

Point::Point() : x(0), y(0)
{
}
Point::Point(double x, double y) : x(x), y(y)
{
}
double Point::Distance(Point b) {
	return sqrt(abs(this->x - b.x) + abs(this->y - b.y));
}

std::ostream& operator<<(std::ostream& stream, Point point)
{
	stream << "(" << point.x << "," << point.y << ")";
	return stream;
}
