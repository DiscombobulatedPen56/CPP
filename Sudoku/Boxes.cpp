#include <istream>
#include "Boxes.h"

Box::Box()
{
	this->values = vector<Cell*>(9);
}

void Box::Set(int pos, Cell* cell)
{
	this->values[pos] = cell;
}

Cell::Cell()
{
	this->value = 0;
	this->values = { 1,2,3,4,5,6,7,8,9 };
}

void Cell::Set(int value)
{
	this->value = value;
	this->values.clear();
}

void Cell::Remove(int value)
{
	this->values.erase(find(this->values.begin(), this->values.end(), value));
}

Box Matrix::GetBox(int row, int col)
{
	int RowIndex = 3 * ((row - 1) / 3) + ((col - 1) / 3) + 1;
	return this->boxes[RowIndex];
}

void Matrix::SetValue(int row, int col, int value)
{
	this->cells[row][col].Set(value);
	for (Cell* c : rows[row].values) {
		c->Remove(value);
	}
	for (Cell* c : columns[col].values) {
		c->Remove(value);
	}
	for (Cell* c : boxes[(row % 3) * 3 + (col / 3)].values) {
		c->Remove(value); 
	}
}

Matrix::Matrix()
{
	cells = vector<vector<Cell>>(9,vector<Cell>(9));
	for (int i = 0; i < 9; i++) {
		Row row;
		for (int j = 0; j < 9; j++) {
			row.Set(j, &cells[i][j]);
		}
		rows.push_back(row);
		Column column;
		for (int k = 0; k < 9; k++) {
			column.Set(k, &cells[k][i]);
		}
		columns.push_back(column);
		int boxI = (i%3)*3, boxJ = (i/3)*3;
		Box box;
		int index = 0;
		for (int z = boxJ; z < boxJ+3; z++) {
			for (int h = boxI; h < boxI+3; h++){
				box.Set(index++, &cells[z][h]);
			}
		}
		boxes.push_back(box);
	}
	
}

void Matrix::MakeMatrix(vector<Box> Matrix)
{
	for (int i = 0; i < this->columns.size(); i++) {
		for (int j = 0; j < this->rows.size(); j++) {
			
		}
	}
}