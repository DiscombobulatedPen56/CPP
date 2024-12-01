#include <iostream>

#include "Point.h"

int main(int argc, char* argv[])
{
    Point p1(1, 2);
    Point p2(7, 5);

    std::cout << p1 + p2 << std::endl;
    return 0;
}
