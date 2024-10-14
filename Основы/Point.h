#pragma once

// Название классов принято писать с большой буквы
class Point
{
    // Поля класса
    int x;
    int y;
public:
    // Конструктор по-умолчанию
    Point() = default;
    // Конструктор с параметрами
    Point(int x, int y);
    double getDistance(const Point& other) const;
};
