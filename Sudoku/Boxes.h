#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Cell;
class Box {
protected:
	vector<Cell*> values;
public:
	Box();
	void Set(int pos, Cell* cell);
};

class Row : public Box {

};

class Column : public Box {

};

class Cell : public Box {
private:
	int value;
	vector<int> values;
public:
	Cell();
	void Set(int value);
};

class Matrix {
private:
	vector<Box> boxes;
	vector<Row> rows;
	vector<Column> columns;
	vector<vector<Cell>> cells;
	Box GetBox(int row, int col);
public:
	void SetValue(int row, int col, int value);
	Matrix();
	void MakeMatrix(vector<Box> Matrix);
};