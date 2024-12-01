#include "Point.h"
#include <cmath>

Point::Point(int x, int y) : x(x), y(y)
{
}

Point::Point() : x(0), y(0)
{
}

double Point::GetDistance(const Point p) const
{
    return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
}

Point Point::operator+(const Point& p) const
{
    return Point(this->x + p.x, this->y + p.y);
}

Point Point::operator-(const Point& p) const
{
    return Point(this->x - p.x, this->y - p.y);
}

std::ostream& operator<<(std::ostream& stream, const Point& p)
{
    return stream << "(" << p.x << ", " << p.y << ")";
}