#pragma once
#include <ostream>

class Point
{
private:
    int x;
    int y;
public:
    Point(int x, int y);
    Point();
    double GetDistance(const Point p) const;
    Point operator+(const Point& p) const;
    Point operator-(const Point& p) const;
    friend std::ostream& operator<<(std::ostream& stream, const Point& p);
};


// Операторы, которые можно перегружать:
// + - * / %  = += -= *= /= %= == != > < >= <= ++ -- <<
// >> && || ! & | ^ ~ &= |= ^= <<= >>= [] () -> new delete , ->*

// Операторы, которые нельзя перегружать: . :: ?: .*


// TODO: Описать тему Дружественные функции
