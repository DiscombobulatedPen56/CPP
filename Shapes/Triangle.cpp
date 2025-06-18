#include "Triangle.h"
#include <cmath>

Triangle::Triangle(Point a, Point b, Point c) : a(a), b(b), c(c)
{
}

double Triangle::Area() 
{
	double s = ((a.Distance(b) + b.Distance(c) + c.Distance(a)) / 2);
	return sqrt(s*(s-a.Distance(b))*(s-b.Distance(c))*(s-c.Distance(a)));
}

double Triangle::Perimeter() {
	return (a.Distance(b) + b.Distance(c) + c.Distance(a));
}

std::ostream& operator<<(std::ostream& stream, Triangle& a) {
	stream << a.a << " " << a.b << " " << a.c;
	return stream;
}
//s = ((a.Distance(b)+b.Distance(c)+c.Distance(a))/2)