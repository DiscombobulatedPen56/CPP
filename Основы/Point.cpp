#include "Point.h"
#include <cmath>

// Быстрая инициализация переменных
Point::Point(int x, int y) : x(x) , y(y) { }

// Альтернативный вариант конструктора с параметрами
/*
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
*/

double Point::getDistance(const Point& other) const
{
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}



