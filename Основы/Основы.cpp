#include <iostream>
#include "Point.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Экземпляр класса Point
    Point p1{};
    Point* p2 = new Point();
    Point* p3 = new Point(7, 10);
    cout << p2->getDistance(*p3);
    return 0;
}
