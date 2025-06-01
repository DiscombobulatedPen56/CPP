#pragma once

class Point {
public:
	double x;
	double y;
	Point();
	Point(double x, double y);
	double Distance(Point b);
};