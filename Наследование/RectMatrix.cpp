#include "RectMatrix.h"

#include <ostream>

RectMatrix::RectMatrix(int rowCount, int colCount)
{
    matrix = std::vector<std::vector<int>>(rowCount, std::vector<int>(colCount, 0));
}

int RectMatrix::GetRowCount()
{
    return matrix.size();
}

int RectMatrix::GetColumnCount()
{
    return matrix.at(0).size();
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const RectMatrix& rectMatrix) {
    for (const auto& row : rectMatrix.matrix) {
        for (const auto& elem : row) {
            os << elem << " ";
        }
        os << std::endl;
    }
    return os;
}
