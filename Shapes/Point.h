#pragma once
#include <ostream>

class Point {
public:
	double x;
	double y;
	Point();
	Point(double x, double y);
	double Distance(Point b);
	friend std::ostream& operator<<(std::ostream& stream, Point& point);
};