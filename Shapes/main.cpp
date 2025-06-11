#include <iostream>
#include <random>
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;

vector<Shape> GenerateShapes(int n) {
	vector<Shape> shapes;
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> range(1, 5);
	uniform_int_distribution<> point_range(-100, 100);
	uniform_int_distribution<> side_range(1, 100);
	for (int i = 0; i < n; i++) {
		Point point(point_range(generator), point_range(generator));
		double side = side_range(generator);
		switch (range(generator)) {
		case 1:
			shapes.push_back(Square(point, side));
			break;
		case 2:
			shapes.push_back(Rectangle(point, side, side_range(generator)));
			break;
		case 3:
			shapes.push_back(Circle(point, side));
			break;
		case 4:
			shapes.push_back(Ellipse(point, side, side_range(generator)));
			break;
		case 5:
			Point point2(point_range(generator), point_range(generator));
			Point point3(point_range(generator), point_range(generator));
			shapes.push_back(Triangle(point, point2, point3));
			break;
		}
	}
	return shapes;
}

int main() {
	int n;
	cin >> n;
	GenerateShapes(n);
	return 0;
}