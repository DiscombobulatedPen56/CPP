#include "Boxes.h"

#include "Position.h"

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

void Cell::Set(int val)
{
    this->value = val;
    this->available.clear();
}

void Cell::Remove(int val)
{
    auto it = std::find(this->available.begin(), this->available.end(), val);
    if (it != this->available.end())
        this->available.erase(it);
}

void Cell::AddToAvailable(int val)
{
    auto it = std::find(this->available.begin(), this->available.end(), val);
    if (it == this->available.end())
        this->available.push_back(val);
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
    int oldValue = this->cells[row][col].getValue();
    this->cells[row][col].Set(value);
    if (value == 0 || oldValue != 0)
    {
        this->cells[row][col].available = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (Cell* c : rows[row].values)
        {
            if (c != &this->cells[row][col])
            {
                c->AddToAvailable(oldValue);
                this->cells[row][col].Remove(c->getValue());
            }
        }
        for (Cell* c : columns[col].values)
        {
            if (c != &this->cells[row][col])
            {
                c->AddToAvailable(oldValue);
                this->cells[row][col].Remove(c->getValue());
            }
        }

        int boxIndex = 3 * ((row - 1) / 3) + ((col - 1) / 3);
        for (Cell* c : boxes[boxIndex].values)
        {
            if (c != &this->cells[row][col])
            {
                c->AddToAvailable(oldValue);
                this->cells[row][col].Remove(c->getValue());
            }
        }
    }
    else
    {
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
}

int Matrix::GetValue(int row, int col)
{
    return this->cells[row][col].getValue();
}

bool Matrix::Solved() const
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!this->cells[i][j].available.empty())
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::Solve(int row, int col)
{
    // If we've reached the end of the matrix, return true
    if (row == 9)
        return true;

    // If current cell is already filled, move to next
    if (this->cells[row][col].getValue() != 0)
    {
        if (col == 8)
            return Solve(row + 1, 0);
        else
            return Solve(row, col + 1);
    }

    // Try all available numbers for this cell
    for (int num = 1; num <= 9; num++)
    {
        if (std::find(this->cells[row][col].available.begin(),
                     this->cells[row][col].available.end(), num) !=
            this->cells[row][col].available.end())
        {
            // Temporarily place the number
            this->SetValue(row, col, num);

            // Recursively try to solve the rest
            bool solved;
            if (col == 8)
                solved = Solve(row + 1, 0);
            else
                solved = Solve(row, col + 1);

            if (solved)
                return true;

            // Backtrack if solution not found
            this->SetValue(row, col, 0);
        }
    }

    return false;
}

Position Matrix::GetFirst()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (!this->cells[i][j].available.empty())
                return {i, j};
    return {0, 0};
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

std::ostream& operator<<(std::ostream& stream, Matrix& a)
{
    stream << " ";
    for (int i = 0; i < 9; i++)
    {
        if (i > 0 && i < 8 && i % 3 == 0)
        {
            stream << "---------------------\n ";
        }
        for (int j = 0; j < 9; j++)
        {
            if (j > 0 && j % 3 == 0)
            {
                stream << "| ";
            }
            stream << a.GetValue(i, j) << " ";
        }
        stream << "\n ";
    }
    stream << "\n\n";
    return stream;
}
