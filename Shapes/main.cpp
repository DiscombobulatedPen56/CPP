#include <iostream>
#include <random>
#include "Shape.h"
#include "Square.h"
#include "Ellipse.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;

vector<shared_ptr<Shape>> GenerateShapes(int n) {
	vector<shared_ptr<Shape>> shapes;
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
			shapes.push_back(make_shared<Square>(point, point_range(generator)));
			break;
		case 2:
			shapes.push_back(make_shared<Rectangle>(point, side, side_range(generator)));
			break;
		case 3:
			shapes.push_back(make_shared<Circle>(point, point_range(generator)));
			break;
		case 4:
			shapes.push_back(make_shared<Ellipse>(point, side, side_range(generator)));
			break;
		case 5:
			Point point2(point_range(generator), point_range(generator));
			Point point3(point_range(generator), point_range(generator));
			shapes.push_back(make_shared<Triangle>(point, point2, point3));
			break;
		}
	}
	return shapes;
}

template<typename T>
std::vector<std::shared_ptr<Shape>> filterByType(std::vector<std::shared_ptr<Shape>> shapes) {
	std::vector<shared_ptr<Shape>> result;
	for (auto &shape:shapes){
		if (typeid(*shape) == typeid(T)) {
			result.push_back(shape);
		}
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<std::shared_ptr<Shape>> shapes = GenerateShapes(n);
	for (int i = 0; i < n; i++) {
		cout << *shapes[i];
	}
	cout << std::endl;
	vector<std::shared_ptr<Shape>> filtered = filterByType<Square>(shapes);
	for (int i = 0; i < filtered.size(); i++) {
		cout << *filtered[i];
	}
	return 0;
}

int smallestAreaShape(vector<std::shared_ptr<Shape>> shapes) {
	int smallest_index = 0;
	for (int i = 0; i < shapes.size(); i++) {
		if (shapes[i]->Area() < shapes[smallest_index]->Area()) {
			smallest_index = i;
		}
	}
	return smallest_index;
}

int greatestAreaShape(vector<std::shared_ptr<Shape>> shapes) {
	int greatest_index = 0;
	for (int i = 0; i < shapes.size(); i++) {
		if (shapes[i]->Area() > shapes[greatest_index]->Area()) {
			greatest_index = i;
		}
	}
	return greatest_index;
}

int smallestPerimeterShape(vector<std::shared_ptr<Shape>> shapes) {
	int smallest_index = 0;
	for (int i = 0; i < shapes.size(); i++) {
		if (shapes[i]->Perimeter() < shapes[smallest_index]->Perimeter()) {
			smallest_index = i;
		}
	}
	return smallest_index;
}

int greatestPerimeterShape(vector<std::shared_ptr<Shape>> shapes) {
	int greatest_index = 0;
	for (int i = 0; i < shapes.size(); i++) {
		if (shapes[i]->Perimeter() > shapes[greatest_index]->Perimeter()) {
			greatest_index = i;
		}
	}
	return greatest_index;
}