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

void Triangle::Print(std::ostream& stream) {
	stream << "Triangle: " << a << " " << b << " " << c << "\n";
}
//s = ((a.Distance(b)+b.Distance(c)+c.Distance(a))/2)