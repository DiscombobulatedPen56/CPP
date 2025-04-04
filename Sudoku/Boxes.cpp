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
    this->available = {1, 2, 3, 4, 5, 6, 7, 8, 9};
}

void Cell::Set(int value)
{
    this->value = value;
    this->available.clear();
}

void Cell::Remove(int value)
{
    auto it = std::find(this->available.begin(), this->available.end(), value);
    if (it != this->available.end())
        this->available.erase(find(this->available.begin(), this->available.end(), value));
}

int Cell::getValue()
{
    return this->value;
}

Box Matrix::GetBox(int row, int col)
{
    int RowIndex = 3 * ((row - 1) / 3) + ((col - 1) / 3);
    return this->boxes[RowIndex];
}

void Matrix::SetValue(int row, int col, int value)
{
    this->cells[row][col].Set(value);
    for (Cell* c : rows[row].values)
    {
        if (c != &this->cells[row][col])
            c->Remove(value);
    }

    for (Cell* c : columns[col].values)
    {
        if (c != &this->cells[row][col])
            c->Remove(value);
    }

    int boxIndex = 3 * ((row - 1) / 3) + ((col - 1) / 3);
    for (Cell* c : boxes[boxIndex].values)
    {
        if (c != &this->cells[row][col])
            c->Remove(value);
    }
}


bool Matrix::Solved()
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (this->cells[i][j].available.size() > 1) {
                return false;
            }
        }
    }
    return true;
}


void Matrix::Solve()
{
    while (!Solved()) {
        Fill();
        FillFirst();
    } 
}

void Matrix::Fill()
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (this->cells[i][j].available.size() == 0) {
                this->cells[i][j].Set(this->cells[i][j].available[0]);
            }
        }
    }
}

void Matrix::FillFirst()
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (this->cells[i][j].available.size() > 1) {
                this->cells[i][j].Set(this->cells[i][j].available[0]);
            }
        }
    }
}

Matrix::Matrix()
{
    cells = vector<vector<Cell>>(9, vector<Cell>(9));
    for (int i = 0; i < 9; i++)
    {
        Row row;
        for (int j = 0; j < 9; j++)
            row.Set(j, &cells[i][j]);
        rows.push_back(row);
        Column column;
        for (int k = 0; k < 9; k++)
            column.Set(k, &cells[k][i]);
        columns.push_back(column);
        int boxJ = (i % 3) * 3, boxI = (i / 3) * 3;
        Box box;
        int index = 0;
        for (int z = boxI; z < boxI + 3; z++)
            for (int h = boxJ; h < boxJ + 3; h++)
                box.Set(index++, &cells[z][h]);
        boxes.push_back(box);
    }
}

std::ostream& operator<<(std::ostream& stream, const Matrix& a)
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            stream << a.cells[i][j].available[0] << ' ';
        }
        stream << '\n'; 
    }
    return stream;
}


