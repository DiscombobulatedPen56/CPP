#include <vector>
#include "Boxes.h"
using namespace std;


int main() {
	Matrix matrix;
	int value = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> value;
			matrix.SetValue(i, j, value);
		}
	}
	matrix.Solve();
	cout << matrix;
	return 0;
}