#include <vector>
#include "Boxes.h"
using namespace std;

int main() {
	Matrix matrix;
	matrix.SetValue(0, 4, 5);
	matrix.SetValue(0, 7, 8);
	matrix.SetValue(1, 0, 4);
	matrix.SetValue(1, 2, 5);
	matrix.SetValue(1, 4, 8);
	matrix.SetValue(1, 5, 6);
	matrix.SetValue(1, 8, 2);
	matrix.SetValue(2, 2, 8);
	matrix.SetValue(2, 4, 9);
	matrix.SetValue(2, 8, 5);
	matrix.SetValue(3, 2, 2);
	matrix.SetValue(3, 3, 5);
	matrix.SetValue(3, 4, 7);
	matrix.SetValue(3, 8, 3);
	matrix.SetValue(4, 1, 8);
	matrix.SetValue(4, 7, 7);
	matrix.SetValue(5, 0, 6);
	matrix.SetValue(5, 4, 3);
	matrix.SetValue(5, 5, 4);
	matrix.SetValue(5, 6, 1);
	matrix.SetValue(6, 0, 7);
	matrix.SetValue(6, 4, 1);
	matrix.SetValue(6, 6, 4);
	matrix.SetValue(7, 0, 5);
	matrix.SetValue(7, 3, 2);
	matrix.SetValue(7, 4, 6);
	matrix.SetValue(7, 6, 9);
	matrix.SetValue(7, 8, 7);
	matrix.SetValue(8, 1, 3);
	matrix.SetValue(8, 4, 4);
	return 0;
}