#pragma once
#include <ostream>
#include <vector>

class RectMatrix
{
// Доступ в классах наследниках
protected:
    std::vector<std::vector<int>> matrix;
public:
    RectMatrix() = default;
    RectMatrix(int rowCount, int columnCount);
    int GetRowCount();
    int GetColumnCount();

    friend std::ostream& operator<<(std::ostream& os, const RectMatrix& rectMatrix);
};
