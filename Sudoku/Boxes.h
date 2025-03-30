#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Cell;
class Box {
public:
	Box();
	void Set(int pos, Cell* cell);
	vector<Cell*> values; //Not good
};

class Row : public Box {

};

class Column : public Box {

};

class Cell : public Box {
	int value;
public:
	Cell();
	void Set(int value);
	void Remove(int value);
	int getValue();
	vector<int> available; //Not good
};

class Matrix {
	vector<Box> boxes;
	vector<Row> rows;
	vector<Column> columns;
	vector<vector<Cell>> cells;
	Box GetBox(int row, int col);
public:
	void SetValue(int row, int col, int value);
	bool Solved();
	void Solve();
	void Fill();
	void FillFirst();
	friend std::ostream& operator<<(ostream& stream, const Matrix& a);
	Matrix();

};