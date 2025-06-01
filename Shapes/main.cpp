#include <iostream>
#include <random>
#include "Shape.h"
using namespace std;

vector<Shape> GenerateShapes(int n) {
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> range(0, 5);
	for (int i = 0; i < n; i++) {
		range(generator);
	}
	return vector<Shape>();
}

int main() {
	int n;
	cin >> n;
	GenerateShapes(n);
	return 0;
}